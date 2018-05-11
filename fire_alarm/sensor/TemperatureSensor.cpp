#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(int pin) {
	this->dallasTemperature = new DallasTemperature (new OneWire(pin));
}

void TemperatureSensor::initialize(){
	this->dallasTemperature->begin();
}

float TemperatureSensor::getEnvironmentTemperature(){
	dallasTemperature->requestTemperatures();       //Prepara el sensor para la lectura

	return dallasTemperature->getTempCByIndex(0); //Se lee la temperatura en grados Centigrados
}

TemperatureSensor::~TemperatureSensor() {

}
