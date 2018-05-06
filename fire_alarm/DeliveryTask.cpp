#include "DeliveryTask.h"
#include "WiFiEspClient.h"

DeliveryTask::DeliveryTask() {

}

void DeliveryTask::sendAlert(const Environment& environment) {

	WiFiEspClient client;

	if(!client.connect("192.168.1.2", 8080)){
		Serial.println("Error to connect to server");
	}else{
		String content = serialize(environment);
			client.print(
					String("POST ") + "/alert" + " HTTP/1.1\r\n" + "Host: "+ "192.168.1.2:8080" + "\r\n"
							+ "Content-Type: application/json\r\n" + "Content-Length: "+ content.length() + "\r\n" + "\r\n" + // This is the extra CR+LF pair to signify the start of a body
							content + "\n");
			Serial.println(content);
			client.stop();
	}


}

String DeliveryTask::serialize(const Environment& environment) {
	StaticJsonBuffer<600> jsonBuffer;
	JsonObject& alert = jsonBuffer.createObject();
	alert["gas"] = environment.getGas();
	alert["temp"] = environment.getTemperature();

	JsonArray& detectionMethod = alert.createNestedArray("det");
	detectionMethod.add("TEMPERATURE");

	JsonObject& latitude = jsonBuffer.createObject();
	latitude["d"] = 34;
	latitude["m"] = 33;
	latitude["s"] = 58.3;
	latitude["cp"] = "SOUTH";

	JsonObject& longitude = jsonBuffer.createObject();
	longitude["d"] = 34;
	longitude["m"] = 33;
	longitude["s"] = 58.3;
	longitude["cp"] = "WEST";

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

DeliveryTask::~DeliveryTask() {

}

