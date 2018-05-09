#ifndef DELIVERYTASK_H_
#define DELIVERYTASK_H_
#include "Environment.h"
#include "WString.h"
#include "ArduinoJson.h"
#include "configuration/Location.h"

class DeliveryTask {

public:
	DeliveryTask();

	void sendAlert(const Environment& environment,  Location location);

	virtual ~DeliveryTask();

private:
	String serialize(const Environment& environment, Location location);

	void logLocation(Location location);
};

#endif /* DELIVERYTASK_H_ */
