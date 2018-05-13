#include "Buzzer.h"

Buzzer::Buzzer(int buzzerPin) {
	this->buzzerPin = buzzerPin;
	pinMode(buzzerPin, OUTPUT);
}

void Buzzer::correctConfiguration() {
	playSound(9000, 0, 200);
}

void Buzzer::alarmOnline() {
	playSound(9000, 500, 200);
	playSound(9000, 500, 200);
}

void Buzzer::configurationError(){
	playSound(2000, 1000, 1000);
	playSound(2000, 1000, 1000);
	playSound(2000, 1000, 1000);
}

void Buzzer::fireDetected(){
	playSound(2000, 500, 300);
}

void Buzzer::playSound(int frequence, int delayMillis, int duration) {
	tone(buzzerPin, frequence, duration);
	delay(delayMillis);
}

Buzzer::~Buzzer() {

}
