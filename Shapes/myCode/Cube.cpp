/*
 * Cube.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Cube.h"

using namespace std;
Cube::Cube(std::string name):Formation(name)
{
}

Cube::~Cube()
{
	// TODO Auto-generated destructor stub
}

int Cube::getArea() const
{
	int area = 0;

	for (auto itr = Formation::shapes3D.begin(); itr!= Formation::shapes3D.end(); itr++)
	{
		area = area + itr->get()->getArea();
	}

	return 6*area;
}

int Cube::getPerimter() const
{
	int perimeter = 0;
	for (auto itr = Formation::shapes3D.begin(); itr!= Formation::shapes3D.end(); itr++)
	{
		perimeter = perimeter + itr->get()->getPerimter();
	}

	return 3*perimeter;
}

Cube* Cube::to_Type(Shape *ptr)
{
	Cube *cubePtr = dynamic_cast<Cube*>(ptr);


	return cubePtr;
}
