#include "Arduino.h"
#include "configuration/Configurator.h"
#include "Visor.h"
#include "Buzzer.h"

AlarmConfiguration alarmConfiguration;

void setup() {
	LiquidCrystal_I2C lcd(0x27, 16, 2);
	Visor visor(&lcd);
	Buzzer buzzer(2);

	Serial.begin(9600);     //console
	Serial1.begin(9600);   //bluetooth
	visor.reportOffLine();

	Configurator configurator(&visor, &buzzer);
	alarmConfiguration = configurator.configureAlarm();
	Serial.println(alarmConfiguration.isCompleted());
}

void loop() {

}
