/*
 * ResistorPart.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef RESISTORPART_H_
#define RESISTORPART_H_


#include <iostream>
#include <string>

#include "Resistor.h"

class ResistorPart: public Resistor
{
private:
	float value;
	float tolerance;
public:
	ResistorPart(std::string name, float value, float tolerance);
	virtual ~ResistorPart();
	float nominalValue()const;
	float minimalValue()const;
	float maximumValue()const;
	void write(std::ostream& out);
	ResisPtr from(std::string line);

};

#endif /* RESISTORPART_H_ */
