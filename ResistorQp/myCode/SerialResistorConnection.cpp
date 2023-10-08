/*
 * SerialResistorConnection.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "SerialResistorConnection.h"

using namespace std;
SerialResistorConnection::SerialResistorConnection(std::string name):ResistorConnection(name)
{
}

SerialResistorConnection::~SerialResistorConnection()
{
	// TODO Auto-generated destructor stub
}

char SerialResistorConnection::seperator() const
{
	return '-';
}

float SerialResistorConnection::nominalValue() const
{
	float nominalVal = 0;
	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		nominalVal += itr->get()->nominalValue();
	}

	return nominalVal;
}

float SerialResistorConnection::minimalValue() const
{
	float minVal = 0;
	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		minVal += itr->get()->minimalValue();
	}

	return minVal;
}

float SerialResistorConnection::maximumValue() const
{
	float maxVal = 0;
	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		maxVal += itr->get()->maximumValue();
	}

	return maxVal;
}
