#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_
#include "AlarmConfiguration.h"
#include "HardwareSerial.h"
#include "ArduinoJson.h"
#include "../Visor.h"
#include "../Buzzer.h"
#include "../connection/ConnectionTask.h"
#include "../message/JsonParser.h"
#include "UrlServer.h"

class Configurator {
	Visor *visor;
	Buzzer* buzzer;
	ConnectionTask* connectionTask;
	JsonParser* jsonParser;

public:
	Configurator(Visor* visor, Buzzer *buzzer, ConnectionTask* connectioTask, JsonParser* jsonParser);
	virtual ~Configurator();

	AlarmConfiguration* configureAlarm();

private:
	Coordinate* deserializeCoordinate(JsonObject& coordinateJson);
};

#endif /* CONFIGURATOR_H_ */
