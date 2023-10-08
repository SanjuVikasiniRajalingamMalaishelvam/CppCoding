/*
 * Shape.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <string>

class Shape
{
private:
	std::string name;
public:
	Shape(std::string name);
	virtual ~Shape();
	virtual int getLength()const =0;
	virtual int getBreadth()const=0;
	virtual int getArea()const=0;
	virtual int getPerimter()const=0;
	virtual std::string getName()const;
	virtual void addShape(Shape* shapePtr);
	std::string toString();
	void write(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& lhs, Shape& rhs);

};

#endif /* SHAPE_H_ */
