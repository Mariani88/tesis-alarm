#ifndef CONNECTIONTASK_H_
#define CONNECTIONTASK_H_
#include "../configuration/WifiNetwork.h"
#include "WiFiEsp.h"
#include "../Visor.h"

class ConnectionTask {

	Visor *visor;

public:

	ConnectionTask(Visor* visor);

	bool initializeWifi();

	bool connectToWifi(WifiNetwork* wifiNetwork);

	void checkConnection(WifiNetwork wifiNetwork);

	virtual ~ConnectionTask();
};

#endif /* CONNECTIONTASK_H_ */
