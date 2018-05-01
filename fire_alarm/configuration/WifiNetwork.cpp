#include "WifiNetwork.h"

WifiNetwork::WifiNetwork(String ssid, String password) {
	this->ssid = ssid;
	this->password = password;
}

String WifiNetwork::getSsid() {
	return ssid;
}

String WifiNetwork::getPassword() {
	return password;
}

bool WifiNetwork::equals(WifiNetwork wifiNetwork) {
	return ssid.equals(wifiNetwork.getSsid())
			&& password.equals(wifiNetwork.getPassword());
}

WifiNetwork::~WifiNetwork() {

}
