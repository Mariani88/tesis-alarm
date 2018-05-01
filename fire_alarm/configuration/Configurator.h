
#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_
#include "AlarmConfiguration.h"
#include "HardwareSerial.h"
#include "ArduinoJson.h"
#include "../Visor.h"

class Configurator {

	Visor *visor;

public:
	Configurator(Visor* visor);
	virtual ~Configurator();

	AlarmConfiguration configureAlarm();

private:
	Coordinate deserializeCoordinate(JsonObject& coordinateJson);
	JsonObject& deserializeMessage(String message);
};

#endif /* CONFIGURATOR_H_ */
