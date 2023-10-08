/*
 * Rectangle.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include <string>
#include <cmath>

#include "Shape.h"

class Rectangle: public Shape
{
private:
	int length;
	int breadth;
	int diagonal;
public:
	Rectangle(std::string name, int length, int breadth);
	virtual ~Rectangle();
	int getLength()const;
	int getBreadth()const;
	int getArea()const;
	int getPerimter()const;
	bool operator==(const Shape& shape);
	bool operator<(const Shape& shape);
};

#endif /* RECTANGLE_H_ */
