/*
 * Shape.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Shape.h"

using namespace std;
Shape::Shape(std::string name)
{
	this->name = name;
}

Shape::~Shape()
{
	// TODO Auto-generated destructor stub
}



std::string Shape::getName() const
{
	return this->name;
}

void Shape::addShape(Shape *shapePtr)
{
}

std::string Shape::toString()
{
	string toStr = "";
	toStr = this->getName() +":"+ to_string(this->getLength()) + "," + to_string(this->getBreadth()) + "," + to_string(this->getArea()) + "," + to_string(this->getPerimter());

	return toStr;
}

void Shape::write(std::ostream &out)
{
	out << toString() <<endl;
}
std::ostream& operator<<(std::ostream& lhs, Shape& rhs)
{
	lhs << rhs.toString();

	return lhs;
}
