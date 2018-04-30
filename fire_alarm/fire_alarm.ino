#include "Arduino.h"
#include "WString.h"
#include "Configurator.h"

void setup() {
	Serial.begin(9600);
	Serial1.begin(9600);

	Configurator configurator;
	configurator.configureAlarm();

}

void loop() {

}
