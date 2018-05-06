#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_
#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor {

	DallasTemperature* dallasTemperature;

public:
	TemperatureSensor(int pin);

	float getEnvironmentTemperature();

	virtual ~TemperatureSensor();
};

#endif /* TEMPERATURESENSOR_H_ */
