/*
 * AlarmConfiguration.h
 *
 *  Created on: Apr 30, 2018
 *      Author: matias
 */

#ifndef ALARMCONFIGURATION_H_
#define ALARMCONFIGURATION_H_

class AlarmConfiguration {
public:
	AlarmConfiguration();
	virtual ~AlarmConfiguration();

	bool isCompleted();

	void setWifiNetwork();

	void setLocation();


};

#endif /* ALARMCONFIGURATION_H_ */
