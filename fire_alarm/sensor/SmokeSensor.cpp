#include "SmokeSensor.h"

SmokeSensor::SmokeSensor(int smokeAI, int smokeDI) {
	this->smokeAI = smokeAI;
	this->smokeDI = smokeDI;
	pinMode(smokeDI, INPUT);
	pinMode(smokeAI, INPUT);
}

bool SmokeSensor::detectSmoke() {
	return digitalRead(smokeDI) == LOW;
}

int SmokeSensor::getEnvironmentGas() {
	return analogRead(smokeAI);
}

SmokeSensor::~SmokeSensor() {

}
