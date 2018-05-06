#include "Environment.h"

Environment::Environment(float temperature, int gas, bool detectFire, bool detectSmoke) {
	this->temperature = temperature;
	this->gas = gas;
	this->detectSmoke = detectSmoke;
	this->detectFire = detectFire;
}

bool Environment::thereIsAFire(){
	return true;
}

Environment::~Environment() {

}

