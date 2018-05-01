#include "Location.h"

	Location::Location(Coordinate* latitude, Coordinate* longitude) {
		this->latitude = latitude;
		this->longitude = longitude;
	}

	const Coordinate* Location::getLatitude() const {
		return latitude;
	}

	const Coordinate* Location::getLongitude() const {
		return longitude;
	}

	Location::~Location(){

	}
