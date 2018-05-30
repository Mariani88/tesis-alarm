#include "CheckStopAlarmTask.h"

const String STOP_ALERT = "STOP_ALERT";

CheckStopAlarmTask::CheckStopAlarmTask(JsonParser* jsonParser) {
	this->jsonParser = jsonParser;
}

bool CheckStopAlarmTask::shouldContinueAlert(){

	if(Serial1.available()){
		JsonObject& json = jsonParser->parse(Serial1.readString());
		String action = json["action"];
		return !action.equals(STOP_ALERT);
	}

	return true;
}

CheckStopAlarmTask::~CheckStopAlarmTask() {

}
