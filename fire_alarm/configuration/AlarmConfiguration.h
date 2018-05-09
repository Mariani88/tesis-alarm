#ifndef ALARMCONFIGURATION_H_
#define ALARMCONFIGURATION_H_

#include "WifiNetwork.h"
#include "Location.h"

class AlarmConfiguration {

	WifiNetwork* wifiNetwork;
	Location* location;

public:
	AlarmConfiguration();
	virtual ~AlarmConfiguration();

	bool isCompleted();

	void setWifiNetwork(WifiNetwork* wifiNetwork);

	void setLocation(Location* location);

	Location getLocation();
};

#endif /* ALARMCONFIGURATION_H_ */
