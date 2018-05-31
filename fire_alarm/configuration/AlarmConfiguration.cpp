#include "AlarmConfiguration.h"

bool wifiConfigurated;
bool locationConfigured;
bool urlServerConfigured;

AlarmConfiguration::AlarmConfiguration() {
	this->wifiNetwork = NULL;
	this->location = NULL;
	this->urlServer = NULL;
}

bool AlarmConfiguration::isCompleted() {
	return wifiConfigurated && locationConfigured && urlServerConfigured;
}

void AlarmConfiguration::setWifiNetwork(WifiNetwork* wifiNetwork) {
	this->wifiNetwork = wifiNetwork;
	wifiConfigurated = true;
}

void AlarmConfiguration::setLocation(Location* location) {
	this->location = location;
	locationConfigured = true;
}

Location AlarmConfiguration::getLocation() {
	return *location;
}

WifiNetwork AlarmConfiguration::getWifiNetwork() {
	return *wifiNetwork;
}

void AlarmConfiguration::setUrlServer(UrlServer* urlServer) {
	this->urlServer = urlServer;
	urlServerConfigured = true;
}

UrlServer AlarmConfiguration::getUrlServer() {
	return *this->urlServer;
}

AlarmConfiguration::~AlarmConfiguration() {

}
