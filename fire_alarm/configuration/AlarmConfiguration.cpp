#include "AlarmConfiguration.h"

bool wifiConfigurated;
bool locationConfigured;

AlarmConfiguration::AlarmConfiguration(){
	this->wifiNetwork = NULL;
	this->location = NULL;
}

bool AlarmConfiguration::isCompleted() {
	return wifiConfigurated && locationConfigured;
}

void AlarmConfiguration::setWifiNetwork(WifiNetwork* wifiNetwork) {
	this->wifiNetwork = wifiNetwork;
	wifiConfigurated = true;
}

void AlarmConfiguration::setLocation(Location* location) {
	this->location = location;
	locationConfigured = true;
}

Location AlarmConfiguration::getLocation(){
	return *location;
}

WifiNetwork AlarmConfiguration::getWifiNetwork(){
	return *wifiNetwork;
}

AlarmConfiguration::~AlarmConfiguration() {

}
