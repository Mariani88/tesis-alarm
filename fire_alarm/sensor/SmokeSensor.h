#ifndef SMOKESENSOR_H_
#define SMOKESENSOR_H_
#include "Arduino.h"

class SmokeSensor {

	int smokeAI;
	int smokeDI;

public:
	SmokeSensor(int smokeAI, int smokeDI);

	bool detectSmoke();

	int getEnvironmentGas();

	virtual ~SmokeSensor();
};

#endif /* SMOKESENSOR_H_ */
