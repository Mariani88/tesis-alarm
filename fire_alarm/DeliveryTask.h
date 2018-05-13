#ifndef DELIVERYTASK_H_
#define DELIVERYTASK_H_
#include "Environment.h"
#include "WString.h"
#include "ArduinoJson.h"
#include "configuration/Location.h"
#include "WiFiEspClient.h"

class DeliveryTask {

public:
	DeliveryTask();

	bool sendAlert(Environment* environment, Location location);

	virtual ~DeliveryTask();

private:
	String serialize(Environment* environment, Location location);

	void logLocation(Location location);

	int receiveResponse(WiFiEspClient* client);

	JsonObject& parseCoordinate(StaticJsonBuffer<600>* jsonBuffer,
			const Coordinate* coordinate);

	void send(String& content, WiFiEspClient& client);
};

#endif /* DELIVERYTASK_H_ */
