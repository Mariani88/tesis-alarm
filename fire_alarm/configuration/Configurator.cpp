#include "Configurator.h"
#include "ActionType.h"
#include "Coordinate.h"

Configurator::Configurator(Visor* visor, Buzzer* buzzer,
		ConnectionTask* connectionTask, JsonParser* jsonParser) {
	this->visor = visor;
	this->buzzer = buzzer;
	this->connectionTask = connectionTask;
	this->jsonParser = jsonParser;
}

AlarmConfiguration* Configurator::configureAlarm() {

	AlarmConfiguration* alarmConfiguration = new AlarmConfiguration();

	while (!alarmConfiguration->isCompleted()) {
		if (Serial1.available()) {
			JsonObject& jsonMessage = jsonParser->parse(Serial1.readString());
			String action = jsonMessage["action"];

			if (action.equals(CONNECT)) {
				String ssid = jsonMessage["ssid"];
				String password = jsonMessage["password"];
				Serial.println(action);
				Serial.println(ssid);
				Serial.println(password);
				delay(100);

				WifiNetwork* wifiNetwork = new WifiNetwork (ssid, password);
				bool connected = connectionTask->connectToWifi(wifiNetwork);

				if (connected) {
					alarmConfiguration->setWifiNetwork(wifiNetwork);
					visor->reportWifiConfigured();
					buzzer->correctConfiguration();
				}else{
					visor->reportErrorConnection();
					buzzer->configurationError();
				}
			}

			if (action.equals(SET_LOCATION)) {
				Coordinate* latitude = deserializeCoordinate(
						jsonMessage["latitude"]);
				Coordinate* longitude = deserializeCoordinate(
						jsonMessage["longitude"]);
				Location* location = new Location(latitude, longitude);
				alarmConfiguration->setLocation(location);
				visor->reportLocationConfigured();
				buzzer->correctConfiguration();
			}

			if(action.equals(SET_SERVER_URL)){
				String ip = jsonMessage["ip"];
				int port = jsonMessage["port"];
				alarmConfiguration->setUrlServer(new UrlServer(ip, port));
			}
		}
	}

	Serial.println("ALARM CONFIGURED");
	visor->reportAlarmConfigured();
	buzzer->alarmOnline();
	return alarmConfiguration;
}

Coordinate* Configurator::deserializeCoordinate(JsonObject& coordinateJson) {
	int degree = coordinateJson["degree"];
	int minute = coordinateJson["minute"];
	const String& second = coordinateJson["second"];
	const String& cardinalPoint = coordinateJson["cardinal_point"];
	Serial.println(degree);
	Serial.println(minute);
	Serial.println(second);
	Serial.println(cardinalPoint);
	return new Coordinate(degree, minute, second, cardinalPoint);
}

Configurator::~Configurator() {
}
