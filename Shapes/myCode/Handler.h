/*
 * Handler.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef HANDLER_H_
#define HANDLER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "Shape.h"
class Handler
{
private:
	std::list<Shape*> shapes;
public:
	Handler();
	virtual ~Handler();
	void run();
	void read(std::istream& in);
};

#endif /* HANDLER_H_ */
