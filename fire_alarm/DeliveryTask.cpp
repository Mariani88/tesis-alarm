#include "DeliveryTask.h"
#include "WiFiEspClient.h"

DeliveryTask::DeliveryTask() {

}

void DeliveryTask::sendAlert(const Environment& environment, Location location) {

	WiFiEspClient client;

	if(!client.connect("192.168.1.4", 8080)){
		Serial.println("Error to connect to server");
	}else{
		String content = serialize(environment, location);
			client.print(
					String("POST ") + "/alert" + " HTTP/1.1\r\n" + "Host: "+ "192.168.1.2:8080" + "\r\n"
							+ "Content-Type: application/json\r\n" + "Content-Length: "+ content.length() + "\r\n" + "\r\n" + // This is the extra CR+LF pair to signify the start of a body
							content + "\n");
			Serial.println(content);
			client.stop();
	}


}

String DeliveryTask::serialize(const Environment& environment, Location location) {
	StaticJsonBuffer<600> jsonBuffer;
	JsonObject& alert = jsonBuffer.createObject();
	alert["gas"] = environment.getGas();
	alert["temp"] = environment.getTemperature();

	JsonArray& detectionMethod = alert.createNestedArray("det");
	detectionMethod.add("TEMPERATURE");

	logLocation(location);

	JsonObject& latitude = jsonBuffer.createObject();
	latitude["d"] = location.getLatitude()->getDegree();
	latitude["m"] = location.getLatitude()->getMinute();
	latitude["s"] = location.getLatitude()->getSecond().toDouble();
	latitude["cp"] = location.getLatitude()->getCardinalPoint();

	JsonObject& longitude = jsonBuffer.createObject();
	longitude["d"] = location.getLongitude()->getDegree();
	longitude["m"] = location.getLongitude()->getMinute();
	longitude["s"] = location.getLongitude()->getSecond().toDouble();
	longitude["cp"] = location.getLongitude()->getCardinalPoint();

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

void DeliveryTask::logLocation(Location location){

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

DeliveryTask::~DeliveryTask() {

}

