#ifndef ALARMCONFIGURATION_H_
#define ALARMCONFIGURATION_H_

#include "WifiNetwork.h"
#include "Location.h"
#include "UrlServer.h"

class AlarmConfiguration {

	WifiNetwork* wifiNetwork;
	Location* location;
	UrlServer* urlServer;

public:
	AlarmConfiguration();
	virtual ~AlarmConfiguration();

	bool isCompleted();

	void setWifiNetwork(WifiNetwork* wifiNetwork);

	void setLocation(Location* location);

	void setUrlServer(UrlServer* urlServer);

	Location getLocation();

	WifiNetwork getWifiNetwork();

	UrlServer getUrlServer();
};

#endif /* ALARMCONFIGURATION_H_ */
