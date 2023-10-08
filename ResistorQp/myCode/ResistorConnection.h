/*
 * ResistorConnection.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef RESISTORCONNECTION_H_
#define RESISTORCONNECTION_H_

#include <iostream>
#include <string>
#include <memory>
#include <list>

#include "Resistor.h"
class ResistorConnection: public Resistor
{
protected:
	std::list<ResisPtr> resistors;
public:
	ResistorConnection(std::string name);
	virtual ~ResistorConnection();
	virtual char seperator()const;
	std::string getName()const;
	ResistorConnection& operator+=(const ResisPtr& resistor);
	void write(std::ostream& out);
};

#endif /* RESISTORCONNECTION_H_ */
