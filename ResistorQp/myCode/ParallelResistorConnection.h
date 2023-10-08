/*
 * ParallelResistorConnection.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef PARALLELRESISTORCONNECTION_H_
#define PARALLELRESISTORCONNECTION_H_

#include <iostream>
#include <string>

#include "ResistorConnection.h"
class ParallelResistorConnection:public ResistorConnection
{
public:
	ParallelResistorConnection(std::string name);
	virtual ~ParallelResistorConnection();
	char seperator()const;
	float nominalValue()const;
	float minimalValue()const;
	float maximumValue()const;
};

#endif /* PARALLELRESISTORCONNECTION_H_ */
