#include "Arduino.h"
#include "configuration/Configurator.h"
#include "Visor.h"
#include "Buzzer.h"
#include "connection/ConnectionTask.h"
#include "sensor/FlameSensor.h"
#include "sensor/SmokeSensor.h"
#include "EnvironmentMonitorTask.h"
#include "sensor/TemperatureSensor.h"
#include "DeliveryTask.h"

const int flameDI = 41;
const int flameAI = A10;

const int smokeAI = A11;
const int smokeDI = 39;
const int temperaturePin = A0;

AlarmConfiguration* alarmConfiguration;
FlameSensor* flameSensor;
SmokeSensor* smokeSensor;
TemperatureSensor* temperatureSensor;
Buzzer* buzzer;
Visor* visor;
EnvironmentMonitorTask* environmentMonitorTask;
DeliveryTask deliveryTask;
ConnectionTask* connectionTask;

void setup() {
	initApplicationContext();
	initializeDevices();
	Configurator configurator(visor, buzzer, connectionTask);
	alarmConfiguration = configurator.configureAlarm();
	logLocation(alarmConfiguration->getLocation());
}

void loop() {
	Serial.println("SCANNING ENVIRONMENT");
	Environment environment =
			environmentMonitorTask->obtainEnvironmentVariables();
	logEnvironmentVariables(environment);
	logLocation(alarmConfiguration->getLocation());

	delay(3000);
	bool alertSent = false;


	while(environment.thereIsAFire()){
		buzzer->fireDetected();

		if(!alertSent){
			alertSent = deliveryTask.sendAlert(&environment, alarmConfiguration->getLocation());
		}
	}
}

void initializeDevices(){
	visor->initialize();
	visor->reportInitializing();
	temperatureSensor->initialize();
	bool initialized = connectionTask->initializeWifi();

	while(!initialized){}
	visor->reportOffLine();
}

void logLocation(Location location){

	Serial.println("logging setted location");
	Serial.println(location.getLatitude()->getDegree());
	Serial.println(location.getLatitude()->getMinute());

	const String& second = location.getLatitude()->getSecond();
	Serial.println(second);
	const String& cardinal = location.getLatitude()->getCardinalPoint();
	Serial.println(cardinal);

}

void logEnvironmentVariables(const Environment& environment) {
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
}

void initApplicationContext() {
	flameSensor = new FlameSensor(flameAI, flameDI);
	smokeSensor = new SmokeSensor(smokeAI, smokeDI);
	temperatureSensor = new TemperatureSensor(temperaturePin);
	environmentMonitorTask = new EnvironmentMonitorTask(temperatureSensor,
			smokeSensor, flameSensor);
	Serial.begin(9600); //console
	Serial1.begin(9600); //bluetooth
	Serial2.begin(115200); //wifi
	visor = new Visor(new LiquidCrystal_I2C(0x27, 16, 2));
	buzzer = new Buzzer(2);
	connectionTask = new ConnectionTask(visor);
}
