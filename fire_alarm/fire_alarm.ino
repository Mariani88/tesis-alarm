#include "Arduino.h"
#include "Configurator.h"

AlarmConfiguration alarmConfiguration;

void setup() {
	Serial.begin(9600);     //console
	Serial1.begin(9600);   //bluetooth

	Configurator configurator;
	alarmConfiguration = configurator.configureAlarm();
	Serial.println(alarmConfiguration.isCompleted());
}

void loop() {

}
