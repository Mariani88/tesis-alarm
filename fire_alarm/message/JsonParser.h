#ifndef JSONPARSER_H_
#define JSONPARSER_H_
#include "ArduinoJson.h"
#include "HardwareSerial.h"

class JsonParser {
public:
	JsonParser();

	JsonObject& parse(String message);

	virtual ~JsonParser();
};

#endif /* JSONPARSER_H_ */
