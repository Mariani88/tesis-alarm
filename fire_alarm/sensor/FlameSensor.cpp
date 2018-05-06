#include "FlameSensor.h"

FlameSensor::FlameSensor(int flameAI, int flameDI) {
	this->flameAI = flameAI;
	this->flameDI = flameDI;
	pinMode(flameDI, INPUT);
	pinMode(flameAI, INPUT);
}

bool FlameSensor::detectingFire() {
	return digitalRead(flameDI) == HIGH;
}

FlameSensor::~FlameSensor() {

}
