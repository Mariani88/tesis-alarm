#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-05-10 23:26:10

#include "Arduino.h"
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

void setup() ;
void loop() ;
void initializeDevices();
void logLocation(Location location);
void logEnvironmentVariables(const Environment& environment) ;
void initApplicationContext() ;

#include "fire_alarm.ino"


#endif
