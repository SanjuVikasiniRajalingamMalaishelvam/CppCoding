/*
 * ResistorConnection.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "ResistorConnection.h"

using namespace std;
ResistorConnection::ResistorConnection(std::string name):Resistor(name)
{
}

ResistorConnection::~ResistorConnection()
{
	// TODO Auto-generated destructor stub
}

char ResistorConnection::seperator() const
{
	char seperator = ',';

	return seperator;
}

std::string ResistorConnection::getName() const
{
	string name = Resistor::getName()+ "[";

	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		name += itr->get()->getName() + this->seperator();
	}

	name.pop_back();
	name += "]";
	return name;
}

ResistorConnection& ResistorConnection::operator +=(const ResisPtr &resistor)
{
	resistors.push_back(resistor);

	return *this;
}

void ResistorConnection::write(std::ostream &out)
{
	for (auto itr = resistors.begin(); itr!= resistors.end(); itr++)
	{
		itr->get()->write(out);
	}
	out << this->getName() << ";";
	Resistor::write(out);
}
