#ifndef BUZZER_H_
#define BUZZER_H_

#include "Arduino.h"

class Buzzer {

	int buzzerPin;

public:

	Buzzer(int buzzerPin);

	void correctConfiguration();

	void alarmOnline();

	void configurationError();

	void fireDetected();

	virtual ~Buzzer();

private:

	void playSound(int frequence, int delayMillis, int duration);

};

#endif /* BUZZER_H_ */
