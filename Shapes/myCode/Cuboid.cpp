/*
 * Cuboid.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Cuboid.h"

using namespace std;
Cuboid::Cuboid(std::string name):Formation(name)
{

}

Cuboid::~Cuboid()
{
	// TODO Auto-generated destructor stub
}

int Cuboid::getArea() const
{
	int area = 0;

	for (auto itr = Formation::shapes3D.begin(); itr!= Formation::shapes3D.end(); itr++)
	{
		area = (area + itr->get()->getArea());
	}

	return 2*area;
}

int Cuboid::getPerimter() const
{
	int perimeter = 0;
	for (auto itr = Formation::shapes3D.begin(); itr!= Formation::shapes3D.end(); itr++)
	{
		perimeter = perimeter + itr->get()->getPerimter();

	}

	return perimeter;
}

Cuboid* Cuboid::to_Type(Shape *ptr)
{
	Cuboid *cuboidPtr = dynamic_cast<Cuboid*>(ptr);
	return cuboidPtr;
}
