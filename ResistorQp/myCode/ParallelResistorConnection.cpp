/*
 * ParallelResistorConnection.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "ParallelResistorConnection.h"

using namespace std;
ParallelResistorConnection::ParallelResistorConnection(std::string name):ResistorConnection(name)
{
}

ParallelResistorConnection::~ParallelResistorConnection()
{
	// TODO Auto-generated destructor stub
}

char ParallelResistorConnection::seperator() const
{
	char seperator = '|';

	return seperator;
}

float ParallelResistorConnection::nominalValue() const
{
	float nominalVal = 0;
	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		nominalVal += 1/(itr->get()->nominalValue());
	}

	return 1/nominalVal;
}

float ParallelResistorConnection::minimalValue() const
{
	float minVal = 0;
	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		minVal += 1/(itr->get()->minimalValue());
	}

	return 1/minVal;
}

float ParallelResistorConnection::maximumValue() const
{
	float maxVal = 0;
	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		maxVal += 1/(itr->get()->maximumValue());
	}

	return 1/maxVal;
}
