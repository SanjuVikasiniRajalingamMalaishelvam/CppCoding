/*
 * ResistorReader.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef RESISTORREADER_H_
#define RESISTORREADER_H_

#include <iostream>
#include <string>
#include <map>

#include "Resistor.h"
#include "ResistorPart.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"

class ResistorReader
{
public:
	ResistorReader();
	virtual ~ResistorReader();
	void read (std::istream& in, std::map<std::string, ResisPtr>& found);
};

#endif /* RESISTORREADER_H_ */
