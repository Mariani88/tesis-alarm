
#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_
#include "AlarmConfiguration.h"
#include "HardwareSerial.h"
#include "ArduinoJson.h"
#include "../Visor.h"
#include "../Buzzer.h"
#include "../connection/ConnectionTask.h"

class Configurator {
	Visor *visor;
	Buzzer* buzzer;
	ConnectionTask* connectionTask;

public:
	Configurator(Visor* visor, Buzzer *buzzer, ConnectionTask* connectioTask);
	virtual ~Configurator();

	AlarmConfiguration* configureAlarm();

private:
	Coordinate* deserializeCoordinate(JsonObject& coordinateJson);
	JsonObject& deserializeMessage(String message);
};

#endif /* CONFIGURATOR_H_ */
