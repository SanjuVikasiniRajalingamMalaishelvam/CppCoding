/*
 * Formation.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef FORMATION_H_
#define FORMATION_H_

#include <iostream>
#include <string>
#include <memory>
#include <set>

#include "Shape.h"

class Formation: public Shape
{
private:
	int cubeCount;
	int cuboidCount;
protected:
	std::set<std::shared_ptr<Shape>> shapes3D;
public:
	Formation(std::string name);
	virtual ~Formation();
	std::string getName()const;
	void addShape(Shape* shapePtr);
	int getLength()const;
	int getBreadth()const;
};

#endif /* FORMATION_H_ */
