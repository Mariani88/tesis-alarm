#include "Configurator.h"
#include "ActionType.h"
#include "Coordinate.h"

Configurator::Configurator(Visor* visor, Buzzer* buzzer,
		ConnectionTask* connectionTask) {
	this->visor = visor;
	this->buzzer = buzzer;
	this->connectionTask = connectionTask;
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
				delay(100);
				WifiNetwork wifiNetwork(ssid, password);

				bool connected = connectionTask->connectToWifi(&wifiNetwork);

				if (connected) {
					alarmConfiguration.setWifiNetwork(&wifiNetwork);
					visor->reportWifiConfigured();
					buzzer->correctConfiguration();
				}else{
					visor->reportErrorConnection();
					buzzer->configurationError();
				}
			}

			if (action.equals(SET_LOCATION)) {
				Coordinate latitude = deserializeCoordinate(
						jsonMessage["latitude"]);
				Coordinate longitude = deserializeCoordinate(
						jsonMessage["longitude"]);
				Location location(&latitude, &longitude);
				alarmConfiguration.setLocation(&location);
				visor->reportLocationConfigured();
				buzzer->correctConfiguration();
			}
		}
	}

	Serial.println("ALARM CONFIGURED");
	visor->reportAlarmConfigured();
	buzzer->alarmOnline();
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
