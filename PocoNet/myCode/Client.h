/*
 * Client.h
 *
 *  Created on: 9 Feb 2023
 *      Author: sanju
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Poco/Net/Socket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"

#include <iostream>
#include <string>

class Client
{
private:
	std::string ipAddress;
	int port;

public:
	Client(std::string ipAddress, int port);
	virtual ~Client();
	void run();





};


#endif /* CLIENT_H_ */
