/*
 * Client.cpp
 *
 *  Created on: 9 Feb 2023
 *      Author: sanju
 */

#include "Client.h"

using namespace std;

Client::Client(std::string ipAddress, int port)
{
	this->ipAddress = ipAddress;
	this->port = port;
}

Client::~Client()
{
	// TODO Auto-generated destructor stub
}

void Client::run()
{
	Poco::Net::SocketAddress addr(ipAddress, port);
	Poco::Net::StreamSocket streamSocket(addr);
	Poco::Net::SocketStream stream(streamSocket);


//	streamSocket.connect(addr);

	stream << "generate" <<endl;

//	char bytes[100];
//	streamSocket.receiveBytes(bytes,100);
//
//	for (int idx = 0; idx < 100; idx++)
//	{
//		cout << bytes[idx];
//	}
	stream.flush();

	std::string line = "";

	getline(stream, line);
	getline(stream, line);

	cout << line <<endl;


	//	 getline(stream, line);


	stream.close();
}
