/*
 * ResistorPart.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "ResistorPart.h"

using namespace std;
ResistorPart::ResistorPart(std::string name, float value, float tolerance):Resistor(name)
{
	this->value = value;
	this->tolerance = tolerance;
}

ResistorPart::~ResistorPart()
{
	// TODO Auto-generated destructor stub
}

float ResistorPart::nominalValue() const
{
	float nominalVal = 0;

	nominalVal = this->value;
	return nominalVal;
}

float ResistorPart::minimalValue() const
{
	float minimumVal = 0;

	minimumVal = this->value - (this->tolerance/100);
	return minimumVal;
}

float ResistorPart::maximumValue() const
{
	float maxVal = 0;
	maxVal = this->value + (this->tolerance/100);

	return maxVal;
}

void ResistorPart::write(std::ostream &out)
{
	out << this->getName() << ";" << this->value << ";" << this->tolerance/100<<endl;
}

ResisPtr ResistorPart::from(std::string line)
{
	string::size_type position = line.find(';');
	string name = line.substr(0, position);
	line.erase(0, position+1);
	position = line.find(';');
	float value = stof(line.substr(0, position));
	line.erase(0, position+1);
	float tolerance = stof(line);

	ResisPtr newResistor =  shared_ptr<Resistor>(new ResistorPart(name, value, tolerance));

	return newResistor;


}
