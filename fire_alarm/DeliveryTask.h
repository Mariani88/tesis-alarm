#ifndef DELIVERYTASK_H_
#define DELIVERYTASK_H_
#include "Environment.h"
#include "WString.h"
#include "ArduinoJson.h"

class DeliveryTask {

public:
	DeliveryTask();

	void sendAlert(const Environment& environment);

	virtual ~DeliveryTask();

private:
	String serialize(const Environment& environment);

};

#endif /* DELIVERYTASK_H_ */
