/*
 * Resistor.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Resistor.h"

using namespace std;

Resistor::Resistor(std::string name)
{
	this->name = name;
}

Resistor::~Resistor()
{
	// TODO Auto-generated destructor stub
}

std::string Resistor::getName() const
{
	return this->name;
}

std::string Resistor::toString() const
{
	string str = "";
	str = this->getName()+"="+to_string(this->nominalValue())+"Ohm";

	return str;
}
std::ostream& operator<<(std::ostream& lhs, Resistor& rhs)
{
	lhs << rhs.toString();
	return lhs;
}

void Resistor::write(std::ostream &out)
{
	out << this->nominalValue() << ";" << this->nominalValue()- this->minimalValue() <<endl;
}
