#include "Arduino.h"
#include "configuration/Configurator.h"
#include "Visor.h"
#include "Buzzer.h"
#include "connection/ConnectionTask.h"

AlarmConfiguration alarmConfiguration;

void setup() {
	Serial.begin(9600);     //console
	Serial1.begin(9600);   //bluetooth
	Serial2.begin(115200);
	LiquidCrystal_I2C lcd(0x27, 16, 2);
	Visor visor(&lcd);
	visor.reportOffLine();
	Buzzer buzzer(2);
	ConnectionTask connectionTask(&visor);



	Configurator configurator(&visor, &buzzer, &connectionTask);
	alarmConfiguration = configurator.configureAlarm();
	Serial.println(alarmConfiguration.isCompleted());
}

void loop() {

}
