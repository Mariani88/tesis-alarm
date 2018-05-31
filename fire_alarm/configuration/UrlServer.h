#ifndef URLSERVER_H_
#define URLSERVER_H_
#include "WString.h"

class UrlServer {

	String ip;
	int port;

public:
	UrlServer(String ip, int port);

	const String& getIp() const {
		return ip;
	}

	int getPort() const {
		return port;
	}

	virtual ~UrlServer();
};

#endif /* URLSERVER_H_ */
