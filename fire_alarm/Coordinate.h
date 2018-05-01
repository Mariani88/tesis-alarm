#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <WString.h>

class Coordinate {

	int degree;
	int minute;
	String second;
	String cardinalPoint;

public:
	Coordinate(int degree, int minute, String second, String cardinalPoint);
	virtual ~Coordinate();

	const String& getCardinalPoint() const;

	int getDegree() const;

	int getMinute() const;

	const String& getSecond() const;
};

#endif /* COORDINATE_H_ */
