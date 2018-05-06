#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

class Environment {

	int gas;
	float temperature;
	bool detectFire;
	bool detectSmoke;

public:
	Environment(float temperature, int gas, bool detectFire, bool detectSmoke);

	bool thereIsAFire();

	bool isDetectFire() const {
		return detectFire;
	}

	bool isDetectSmoke() const {
		return detectSmoke;
	}

	int getGas() const {
		return gas;
	}

	float getTemperature() const {
		return temperature;
	}

	virtual ~Environment();
};

#endif /* ENVIRONMENT_H_ */
