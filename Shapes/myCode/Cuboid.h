/*
 * Cuboid.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef CUBOID_H_
#define CUBOID_H_

#include "Formation.h"
#include <memory>

class Cuboid: public Formation
{
public:
	Cuboid(std::string name);
	virtual ~Cuboid();
	int getArea()const;
	int getPerimter()const;
	static Cuboid* to_Type(Shape* ptr);
};

#endif /* CUBOID_H_ */
