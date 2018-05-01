#include "Coordinate.h"

Coordinate::Coordinate(int degree, int minute, String second,
		String cardinalPoint) {
	this->degree = degree;
	this->minute = minute;
	this->second = second;
	this->cardinalPoint = cardinalPoint;
}

const String& Coordinate::getCardinalPoint() const {
	return cardinalPoint;
}

int Coordinate::getDegree() const {
	return degree;
}

int Coordinate::getMinute() const {
	return minute;
}

const String& Coordinate::getSecond() const {
	return second;
}

Coordinate::~Coordinate(){

}
