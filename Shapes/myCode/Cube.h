/*
 * Cube.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Formation.h"

class Cube: public Formation
{
public:
	Cube(std::string name);
	virtual ~Cube();
	int getArea()const;
	int getPerimter()const;
	static Cube* to_Type(Shape* ptr);
};

#endif /* CUBE_H_ */
