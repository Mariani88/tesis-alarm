#ifndef ENVIRONMENTMONITORTASK_H_
#define ENVIRONMENTMONITORTASK_H_
#include "sensor/TemperatureSensor.h"
#include "sensor/SmokeSensor.h"
#include "sensor/FlameSensor.h"
#include "Environment.h"

class EnvironmentMonitorTask {

	TemperatureSensor* temperatureSensor;
	SmokeSensor* smokeSensor;
	FlameSensor* flameSensor;

public:
	EnvironmentMonitorTask(TemperatureSensor* temperatureSensor,
			SmokeSensor* smokeSensor, FlameSensor* flameSensor);

	Environment obtainEnvironmentVariables();

	virtual ~EnvironmentMonitorTask();
};

#endif /* ENVIRONMENTMONITORTASK_H_ */
