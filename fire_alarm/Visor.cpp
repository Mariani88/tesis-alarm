#include "Visor.h"

Visor::Visor(LiquidCrystal_I2C *lcd) {
	this->lcd = lcd;
	this->lcd->init();
	this->lcd->backlight();
}

void Visor::reportWifiConfigured() {
	lcd->setCursor(0,0);
	lcd->print("WIFI OK         ");
}

void Visor::reportLocationConfigured() {
	lcd->setCursor(0, 1);
	lcd->print("LOCATION OK     ");
}

void Visor::reportAlarmConfigured(){
	lcd->clear();
	lcd->print("ALARM ONLINE");
}

void Visor::reportOffLine(){
	lcd->clear();
	lcd->print("Wifi offline");
	lcd->setCursor(0,1);
	lcd->print("Location offline");
}

void Visor::reportErrorConnection(){
	lcd->setCursor(0,0);
	lcd->print("Wifi not connect");
}

void Visor::reportConnecting(){
	lcd->setCursor(0,0);
	lcd->print("Connecting...   ");
}

Visor::~Visor() {

}
