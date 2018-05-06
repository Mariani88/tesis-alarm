#include "EnvironmentMonitorTask.h"

EnvironmentMonitorTask::EnvironmentMonitorTask(
		TemperatureSensor* temperatureSensor, SmokeSensor* smokeSensor,
		FlameSensor* flameSensor) {
	this->flameSensor = flameSensor;
	this->smokeSensor = smokeSensor;
	this->temperatureSensor = temperatureSensor;
}

Environment EnvironmentMonitorTask::obtainEnvironmentVariables() {
	bool detectFire = flameSensor->detectingFire();
	bool detectSmoke = smokeSensor->detectSmoke();
	float temperature = temperatureSensor->getEnvironmentTemperature();
	int gas = smokeSensor->getEnvironmentGas();
	return Environment(temperature, gas, detectFire, detectSmoke);
}

EnvironmentMonitorTask::~EnvironmentMonitorTask() {

}
