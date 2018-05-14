#include "ConnectionTask.h"

ConnectionTask::ConnectionTask(Visor* visor) {
	this->visor = visor;
}

bool ConnectionTask::initializeWifi(){
	WiFi.init(&Serial2);
	bool initialized = WiFi.status() !=WL_NO_SHIELD;
	if(!initialized) visor->reportWifiIsNotInitialized();

	return initialized;
}

bool ConnectionTask::connectToWifi(WifiNetwork* wifiNetwork) {
	char* ssid = new char[wifiNetwork->getSsid().length()];
	sprintf(ssid, "%1s", wifiNetwork->getSsid().c_str());
	char* password = new char[wifiNetwork->getPassword().length()];
	sprintf(password, "%1s", wifiNetwork->getPassword().c_str());
	int status = WL_DISCONNECTED;
	int retry = 0;
	visor->reportConnecting();

	while(status!= WL_CONNECTED && retry < 3){
		Serial.println("connecting");
		status = WiFi.begin(ssid, password);
		delay(100);
		retry++;
		Serial.print("retries:");
		Serial.println(retry);
		Serial.print("connect:");
		Serial.println(status == WL_CONNECTED);
	}

	return WL_CONNECTED == status;
}

void ConnectionTask::checkConnection(WifiNetwork wifiNetwork){

	if(WiFi.status() != WL_CONNECTED){
		Serial.println("Reconnecting before send alert...");
		connectToWifi(&wifiNetwork);
	}
}

ConnectionTask::~ConnectionTask() {

}
