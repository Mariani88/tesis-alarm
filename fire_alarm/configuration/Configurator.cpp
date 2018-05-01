#include "Configurator.h"
#include "ConfigurationType.h"
#include "Coordinate.h"

Configurator::Configurator(Visor* visor) {
	this->visor = visor;
}

AlarmConfiguration Configurator::configureAlarm() {

	AlarmConfiguration alarmConfiguration;

	while (!alarmConfiguration.isCompleted()) {
		if (Serial1.available()) {
			JsonObject& jsonMessage = deserializeMessage(Serial1.readString());
			String action = jsonMessage["action"];

			if (action.equals(CONNECT)) {
				String ssid = jsonMessage["ssid"];
				String password = jsonMessage["password"];
				Serial.println(action);
				Serial.println(ssid);
				Serial.println(password);
				WifiNetwork wifiNetwork(ssid, password);
				alarmConfiguration.setWifiNetwork(&wifiNetwork);
				visor->reportWifiConfigured();
			}

			if (action.equals(SET_LOCATION)) {
				Coordinate latitude = deserializeCoordinate(
						jsonMessage["latitude"]);
				Coordinate longitude = deserializeCoordinate(
						jsonMessage["longitude"]);
				Location location(&latitude, &longitude);
				alarmConfiguration.setLocation(&location);
				visor->reportLocationConfigured();
			}
		}
	}

	Serial.println("ALARM CONFIGURED");
	visor->reportAlarmConfigured();
	return alarmConfiguration;
}

JsonObject& Configurator::deserializeMessage(String message) {
	DynamicJsonBuffer jsonBuffer(512);
	Serial.println(message);
	return jsonBuffer.parseObject(message);
}

Coordinate Configurator::deserializeCoordinate(JsonObject& coordinateJson) {
	int degree = coordinateJson["degree"];
	int minute = coordinateJson["minute"];
	String second = coordinateJson["second"];
	String cardinalPoint = coordinateJson["cardinal_point"];
	Serial.println(degree);
	Serial.println(minute);
	Serial.println(second);
	Serial.println(cardinalPoint);
	return Coordinate(degree, minute, second, cardinalPoint);
}

Configurator::~Configurator() {
}
