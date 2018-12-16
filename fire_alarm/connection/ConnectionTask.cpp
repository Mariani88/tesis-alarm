#include "ConnectionTask.h"

ConnectionTask::ConnectionTask(Visor* visor) {
	this->visor = visor;
}

String ConnectionTask::connectionStatus(){
	String connectionStatus = "";

	switch(WiFi.status()){
	case WL_NO_SHIELD:
		connectionStatus = "WL_NO_SHIELD";
		break;
	case WL_IDLE_STATUS:
		connectionStatus = "WL_IDLE_STATUS";
		break;
	case WL_CONNECTED:
		connectionStatus = "WL_CONNECTED";
		break;
	case WL_CONNECT_FAILED:
		connectionStatus = "WL_CONNECT_FAILED";
		break;
	case WL_DISCONNECTED:
		connectionStatus = "WL_DISCONNECTED";
		break;
	default:
		connectionStatus = "ERROR TO OBTAIN WIFI STATUS";
		break;
	}

	return connectionStatus;
}

bool ConnectionTask::initializeWifi(){
	WiFi.init(&Serial2);
	Serial.println(connectionStatus());
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

	visor->reportAlarmConfigured();
}

ConnectionTask::~ConnectionTask() {

}
