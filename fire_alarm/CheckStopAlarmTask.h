#ifndef CHECKSTOPALARMTASK_H_
#define CHECKSTOPALARMTASK_H_
#include "message/JsonParser.h"
#include "HardwareSerial.h"

class CheckStopAlarmTask {

	JsonParser* jsonParser;

public:
	CheckStopAlarmTask(JsonParser* jsonParser);

	bool shouldContinueAlert();

	virtual ~CheckStopAlarmTask();
};

#endif /* CHECKSTOPALARMTASK_H_ */
