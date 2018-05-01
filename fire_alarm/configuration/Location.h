#ifndef LOCATION_H_
#define LOCATION_H_
#include "Coordinate.h"

class Location {

	Coordinate* latitude;
	Coordinate* longitude;

public:
	Location(Coordinate* latitude, Coordinate* longitude);

	const Coordinate* getLatitude() const;

	const Coordinate* getLongitude() const;

	virtual ~Location();
};

#endif /* LOCATION_H_ */
