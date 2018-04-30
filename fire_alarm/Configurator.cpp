#include "Configurator.h"
#include "ArduinoJson.h"
#include "ConfigurationType.h"

Configurator::Configurator() {

}

AlarmConfiguration Configurator::configureAlarm() {

	while (true) {
		if (Serial1.available()) {
			DynamicJsonBuffer jsonBuffer(512);
			String message = Serial1.readString();
			Serial.println(message);
			JsonObject& root = jsonBuffer.parseObject(message);
			String action = root["action"];

			if (action.equals(CONNECT)) {
				String ssid = root["ssid"];
				String password = root["password"];
				Serial.println(action);
				Serial.println(ssid);
				Serial.println(password);
			}

			if (action.equals(SET_LOCATION)) {
				int degree = root["latitude"]["degree"];
				int minute = root["latitude"]["minute"];
				String second = root["latitude"]["second"];
				String cardinalPoint = root["latitude"]["cardinal_point"];

				Serial.println(action);
				Serial.println(degree);
				Serial.println(minute);
				Serial.println(second);
				Serial.println(cardinalPoint);
			}
		}
	}

	return AlarmConfiguration();
}

Configurator::~Configurator() {
	// TODO Auto-generated destructor stub
}
