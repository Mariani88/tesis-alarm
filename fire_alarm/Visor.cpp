#include "Visor.h"

Visor::Visor(LiquidCrystal_I2C *lcd) {
	this->lcd = lcd;
}

void Visor::initialize() {
	this->lcd->init();
	this->lcd->backlight();
}

void Visor::reportWifiConfigured() {
	lcd->setCursor(0, 0);
	lcd->print("WIFI OK");
}

void Visor::reportLocationConfigured() {
	lcd->setCursor(0, 1);
	lcd->print("LOC OK  ");
}

void Visor::reportUrlServerConfigured(){
	lcd->setCursor(9, 1);
	lcd->print("URLS OK ");
}

void Visor::reportAlarmConfigured() {
	lcd->clear();
	lcd->print("ALARM ONLINE");
}

void Visor::reportOffLine() {
	lcd->clear();
	lcd->print("Wifi NC");
	lcd->setCursor(9, 1);
	lcd->print("urlS NC ");
	lcd->setCursor(0, 1);
	lcd->print("Loc NC  ");
}

void Visor::reportErrorConnection() {
	lcd->setCursor(0, 0);
	lcd->print("Wifi not connect");
}

void Visor::reportConnecting() {
	lcd->setCursor(0, 0);
	lcd->print("Connecting...   ");
}

void Visor::reportWifiIsNotInitialized() {
	lcd->setCursor(0, 0);
	lcd->print("WIFI NOT FOUND  ");
}

void Visor::reportInitializing(){
	lcd->setCursor(0, 0);
	lcd->print("INITIALIZING... ");
}

Visor::~Visor() {

}
