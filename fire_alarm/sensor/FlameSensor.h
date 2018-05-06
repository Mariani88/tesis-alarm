#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_
#include "Arduino.h"

class FlameSensor {

	int flameAI;
	int flameDI;

public:

	FlameSensor(int flameAI, int flameDI);

	bool detectingFire();

	virtual ~FlameSensor();
};

#endif /* FLAMESENSOR_H_ */
