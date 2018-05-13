#include "DeliveryTask.h"

const String SMOKE = "SMOKE";
const String TEMPERATURE = "TEMPERATURE";
const String FIRE = "FIRE";

DeliveryTask::DeliveryTask() {

}

bool DeliveryTask::sendAlert(Environment* environment,
		Location location) {

	WiFiEspClient client;
	int retries = 0;
	int successOk = 200;
	int code = 100;

	if (!client.connect("192.168.1.6", 8080)) {
		Serial.println("Error to connect to server");
	} else {
		while (retries < 6 && code != successOk) {
			String content = serialize(environment, location);
			send(content, client);
			delay(4000);
			code = receiveResponse(&client);
			client.stop();
			retries++;
		}
	}
	return code == successOk;
}

int DeliveryTask::receiveResponse(WiFiEspClient* client) {
	int httpCode = 100;

	if (client->available()) {
		String line = client->readStringUntil('\r');
		Serial.println("response:" + line);
		String code = line.substring(line.indexOf(' ') + 1, line.length());
		Serial.println(code);
		httpCode = code.toInt();
		client->flush();
	}
	return httpCode;
}

String DeliveryTask::serialize(Environment* environment,
		Location location) {
	StaticJsonBuffer<600> jsonBuffer;
	JsonObject& alert = jsonBuffer.createObject();
	alert["gas"] = environment->getGas();
	alert["temp"] = environment->getTemperature();

	JsonArray& detectionMethod = alert.createNestedArray("det");

	if(environment->isDetectFire()) detectionMethod.add(FIRE);
	if(environment->isDetectSmoke()) detectionMethod.add(SMOKE);
	if(environment->highTemperature()) detectionMethod.add(TEMPERATURE);

	logLocation(location);

	JsonObject& latitude = parseCoordinate(&jsonBuffer, location.getLatitude());
	JsonObject& longitude = parseCoordinate(&jsonBuffer,
			location.getLongitude());

	JsonObject& coordinates = jsonBuffer.createObject();
	coordinates["lat"] = latitude;
	coordinates["long"] = longitude;

	alert.createNestedObject("coor");
	alert["coor"] = coordinates;

	String jsonString;

	alert.printTo(jsonString);
	Serial.print(jsonString);

	return jsonString;
}

JsonObject& DeliveryTask::parseCoordinate(StaticJsonBuffer<600>* jsonBuffer,
		const Coordinate* coordinate) {
	JsonObject& coordinateJson = jsonBuffer->createObject();
	coordinateJson["d"] = coordinate->getDegree();
	coordinateJson["m"] = coordinate->getMinute();
	coordinateJson["s"] = coordinate->getSecond().toDouble();
	coordinateJson["cp"] = coordinate->getCardinalPoint();

	return coordinateJson;
}

void DeliveryTask::logLocation(Location location) {
	Serial.println("logging location before serialize");
	Serial.println(location.getLatitude()->getDegree());
	Serial.println(location.getLatitude()->getMinute());
	Serial.println(location.getLatitude()->getSecond().toDouble());
	Serial.println(location.getLatitude()->getCardinalPoint());

	Serial.println(location.getLongitude()->getDegree());
	Serial.println(location.getLongitude()->getMinute());
	Serial.println(location.getLongitude()->getSecond().toDouble());
	Serial.println(location.getLongitude()->getCardinalPoint());
}

void DeliveryTask::send(String& content, WiFiEspClient& client) {
	client.print(
			String("POST ") + "/alert" + " HTTP/1.1\r\n" + "Host: "
					+ "192.168.1.6:8080" + "\r\n"
					+ "Content-Type: application/json\r\n" + "Content-Length: "
					+ content.length() + "\r\n" + "\r\n" + // This is the extra CR+LF pair to signify the start of a body
					content + "\n");
	Serial.println(content);
}

DeliveryTask::~DeliveryTask() {

}

