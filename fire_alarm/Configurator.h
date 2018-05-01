
#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_
#include "AlarmConfiguration.h"
#include "HardwareSerial.h"
#include "ArduinoJson.h"

class Configurator {

public:
	Configurator();
	virtual ~Configurator();

	AlarmConfiguration configureAlarm();

private:
	Coordinate deserializeCoordinate(JsonObject& coordinateJson);

};

#endif /* CONFIGURATOR_H_ */
