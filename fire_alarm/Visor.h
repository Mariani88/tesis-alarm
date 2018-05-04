#ifndef VISOR_H_
#define VISOR_H_

#include "LiquidCrystal_I2C.h"

class Visor {

	LiquidCrystal_I2C *lcd;

public:
	Visor(LiquidCrystal_I2C *lcd);

	void reportWifiConfigured();

	void reportLocationConfigured();

	void reportAlarmConfigured();

	void reportOffLine();

	void reportErrorConnection();

	void reportConnecting();

	virtual ~Visor();
};

#endif /* VISOR_H_ */
