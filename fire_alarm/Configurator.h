
#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_
#include "AlarmConfiguration.h"
#include "HardwareSerial.h"

class Configurator {

public:
	Configurator();
	virtual ~Configurator();

	AlarmConfiguration configureAlarm();
};

#endif /* CONFIGURATOR_H_ */
