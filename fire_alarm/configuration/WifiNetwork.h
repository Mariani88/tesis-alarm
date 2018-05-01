#ifndef WIFINETWORK_H_
#define WIFINETWORK_H_

#include "WString.h"

class WifiNetwork {

	String ssid;
	String password;

public:

	WifiNetwork(String ssid, String password);
	virtual ~WifiNetwork();

	String getSsid();

	String getPassword();

	bool equals(WifiNetwork other);
};

#endif /* WIFINETWORK_H_ */
