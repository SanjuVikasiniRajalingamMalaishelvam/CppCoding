/*
 * Resistor.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_

#include <iostream>
#include <string>
#include <memory>
class Resistor
{
private:
	std::string name;
public:
	Resistor(std::string name);
	virtual ~Resistor();
	std::string getName()const;
	virtual float nominalValue()const = 0;
	virtual float minimalValue()const= 0;
	virtual float maximumValue()const = 0;
	std::string toString()const;
	friend std::ostream& operator<<(std::ostream& lhs, Resistor& rhs);
	virtual void write(std::ostream& out);
};

typedef std::shared_ptr<Resistor> ResisPtr;
#endif /* RESISTOR_H_ */
