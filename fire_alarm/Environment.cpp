#include "Environment.h"

Environment::Environment(float temperature, int gas, bool detectFire,
		bool detectSmoke) {
	this->temperature = temperature;
	this->gas = gas;
	this->detectSmoke = detectSmoke;
	this->detectFire = detectFire;
}

bool Environment::thereIsAFire() {
	return fireSmokeAndHighTemperature() || fireAndHighTemperature()
			|| smokeAndHighTemperature() || fireAndSmoke();
}

bool Environment::fireSmokeAndHighTemperature() {
	return (temperature > 40 && detectFire && detectSmoke);
}

bool Environment::fireAndHighTemperature() {
	return (temperature > 40.0 && detectFire);
}

bool Environment::smokeAndHighTemperature() {
	return (temperature > 40.0 && detectSmoke);
}

bool Environment::highTemperature(){
	return temperature > 40.0;
}

bool Environment::fireAndSmoke() {
	return (detectFire && detectSmoke);
}

Environment::~Environment() {

}

