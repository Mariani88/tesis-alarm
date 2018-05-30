#include "JsonParser.h"

JsonParser::JsonParser() {

}

JsonObject& JsonParser::parse(String message) {
	DynamicJsonBuffer jsonBuffer(512);
	Serial.println(message);
	return jsonBuffer.parseObject(message);
}

JsonParser::~JsonParser() {

}
