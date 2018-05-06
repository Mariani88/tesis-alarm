#include "Arduino.h"
#include "configuration/Configurator.h"
#include "Visor.h"
#include "Buzzer.h"
#include "connection/ConnectionTask.h"
#include "sensor/FlameSensor.h"
#include "sensor/SmokeSensor.h"
#include "EnvironmentMonitorTask.h"
#include "sensor/TemperatureSensor.h"

const int flameDI = 41;
const int flameAI = A10;

const int smokeAI = A11;
const int smokeDI = 39;
const int temperaturePin = A0;

AlarmConfiguration alarmConfiguration;
FlameSensor* flameSensor;
SmokeSensor* smokeSensor;
TemperatureSensor* temperatureSensor;
Buzzer* buzzer;
Visor* visor;
EnvironmentMonitorTask* environmentMonitorTask;

void setup() {
	flameSensor = new FlameSensor(flameAI, flameDI);
	smokeSensor = new SmokeSensor(smokeAI, smokeDI);
	temperatureSensor = new TemperatureSensor(temperaturePin);

	environmentMonitorTask = new EnvironmentMonitorTask(temperatureSensor,
			smokeSensor, flameSensor);

	Serial.begin(9600);     //console
	Serial1.begin(9600);   //bluetooth
	Serial2.begin(115200);
	LiquidCrystal_I2C lcd(0x27, 16, 2);
	visor = new Visor(&lcd);
	visor->reportOffLine();
	buzzer = new Buzzer(2);
	ConnectionTask connectionTask(visor);

	Configurator configurator(visor, buzzer, &connectionTask);
	//alarmConfiguration = configurator.configureAlarm();
	//Serial.println(alarmConfiguration.isCompleted());
}

void loop() {

	Environment environment = environmentMonitorTask->obtainEnvironmentVariables();

	Serial.print("gas:");
	Serial.println(environment.getGas());

	Serial.print("temperature:");
	Serial.println(environment.getTemperature());

	Serial.print("fire detected:");
	Serial.println(environment.isDetectFire());

	Serial.print("smoke detected:");
	Serial.println(environment.isDetectSmoke());
	Serial.println();
	Serial.println("**************************************************");

	delay(5000);

}

