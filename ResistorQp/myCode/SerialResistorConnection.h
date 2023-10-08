/*
 * SerialResistorConnection.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef SERIALRESISTORCONNECTION_H_
#define SERIALRESISTORCONNECTION_H_


#include <iostream>
#include <string>
#include "ResistorConnection.h"
class SerialResistorConnection: public ResistorConnection
{
public:
	SerialResistorConnection(std::string name);
	virtual ~SerialResistorConnection();
	char seperator()const;
	float nominalValue()const;
	float minimalValue()const;
	float maximumValue()const;
};

#endif /* SERIALRESISTORCONNECTION_H_ */
