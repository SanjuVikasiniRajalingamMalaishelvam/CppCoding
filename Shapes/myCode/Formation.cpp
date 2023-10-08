/*
 * Formation.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Formation.h"
#include "Cube.h"
#include "Cuboid.h"

using namespace std;
Formation::Formation(std::string name): Shape(name)
{
	this->cubeCount = 0;
	this->cuboidCount = 0;
}

Formation::~Formation()
{
	// TODO Auto-generated destructor stub
}

std::string Formation::getName() const
{
	string nameShapes = "";
	nameShapes = Shape::getName() + "[";

	for (auto itr = shapes3D.begin(); itr!= shapes3D.end(); itr++)
	{
		nameShapes = nameShapes + itr->get()->getName() + "+";
	}
	if (shapes3D.size() > 0)
	{
		nameShapes.pop_back();
	}


	nameShapes = nameShapes + "]";

	return nameShapes;
}

void Formation::addShape(Shape *shapePtr)
{
	Cube *cubePtr = Cube::to_Type(this);
	Cuboid *cuboidPtr = Cuboid::to_Type(this);
	if (nullptr!= cubePtr)
	{
		if ((cubePtr->getLength() == shapePtr->getLength()) && (cubePtr->getBreadth() == shapePtr->getBreadth()))
		{
			throw std::invalid_argument("Invalid addition - set is Shape");
		}
		else if (cubeCount >= 1)
		{
			throw std::invalid_argument("Invalid addition - set is full(Cube)");
		}
		else
		{
			shapes3D.insert(shared_ptr<Shape>(shapePtr));
			cubeCount++;

		}
	}
	if (nullptr!= cuboidPtr)
	{
		if (cuboidCount < 3)
		{
			shapes3D.insert(shared_ptr<Shape>(shapePtr));
			cuboidCount++;
		}
		else
		{
			throw std::invalid_argument("Invalid addition - set is full(Cuboid)");
		}
	}
}

int Formation::getLength() const
{
	return 0;
}

int Formation::getBreadth() const
{
	return 0;
}
