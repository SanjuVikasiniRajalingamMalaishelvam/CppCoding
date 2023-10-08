/*
 * Thread.h
 *
 *  Created on: 9 Feb 2023
 *      Author: sanju
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <iostream>
#include <string>

#include "Poco/Thread.h"
#include "Poco/Runnable.h"


class Thread
{
private:
	std::string name;
	std::string age;
public:
	Thread(std::string name, std::string age);
	virtual ~Thread();
	void create();
	void getNames();
};

#endif /* THREAD_H_ */
