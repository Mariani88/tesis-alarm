#include "Arduino.h"
#include "WString.h"
#include "ArduinoJson.h"

//The setup function is called once at startup of the sketch
void setup()
{

	Serial.begin(9600);
	char order[] = "{\"action\":\"CONNECT\",\"ssid\": \"red\",\"password\":\"contrasena\" }";

	DynamicJsonBuffer jsonBuffer(512);

	JsonObject& root = jsonBuffer.parseObject(order);


	String action = root["action"];
	String ssid = root["ssid"];
	String password = root["password"];
	Serial.println(ssid);
	Serial.println(action);
	Serial.println(password);

	char locationOrder[] = "{ \"action\":\"SET_LOCATION\", \"latitude\": { \"degree\": 33 ,\"minute\":10, \"second\":45.2345, \"cardinal_point\":\"SOUTH\"}}";
	JsonObject& location  = jsonBuffer.parseObject(locationOrder);

	String action2 = location["action"];

	int degree = location["latitude"]["degree"];
	int minute = location["latitude"]["minute"];
	double second = location["latitude"]["second"];
	String cardinalPoint = location["latitude"]["cardinal_point"];

	Serial.println(action2);
	Serial.println(degree);
	Serial.println(minute);
	Serial.println(second);
	Serial.println(cardinalPoint);

}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
