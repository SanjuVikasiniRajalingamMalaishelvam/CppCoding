/*
 * Rectangle.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(std::string name, int length, int breadth):Shape(name)
{
	this->length = length;
	this->breadth = breadth;
	this->diagonal = std::hypot(this->length,this->breadth);
}

Rectangle::~Rectangle()
{
	// TODO Auto-generated destructor stub
}

int Rectangle::getLength() const
{
	return this->length;
}

int Rectangle::getBreadth() const
{
	return this->breadth;
}

int Rectangle::getArea() const
{
	int area = this->length*this->breadth;

	return area;
}

int Rectangle::getPerimter() const
{
	int perimeter = 2*(this->length+this->breadth);
	return perimeter;
}

bool Rectangle::operator ==(const Shape& data)
{
	bool RC = false;
	if (this->length == data.getLength() && this->breadth == data.getBreadth())
	{
		RC = true;
	}
	return RC;
}

bool Rectangle::operator <(const Shape& shape)
{
	bool RC = false;
	if (this->getArea() < shape.getArea())
	{
		RC = true;
	}
	else if (this->getArea() == shape.getArea())
	{
		if (this->length < shape.getLength())
		{
			RC = true;
		}

	}
	return RC;
}
