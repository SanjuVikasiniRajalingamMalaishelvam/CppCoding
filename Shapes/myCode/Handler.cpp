/*
 * Handler.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Handler.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Cuboid.h"

using namespace std;
Handler::Handler()
{
	// TODO Auto-generated constructor stub

}

Handler::~Handler()
{
	// TODO Auto-generated destructor stub
}

void Handler::run()
{
	Shape *square1 = new Rectangle("square1", 10, 10);
	Shape *rectangle1 = new Rectangle("rectangle1", 10, 15);

	cout << *square1 <<endl;
	cout << *rectangle1 <<endl;

	Shape *rectangle2 = new Rectangle("rectangle2", 15, 5);
	Shape *rectangle3 = new Rectangle("rectangle3", 10, 5);

	cout << *rectangle2 <<endl;
	cout << *rectangle3 <<endl;

	Shape *cubePtr = new Cube("Cube");
	cubePtr->addShape(square1);


	Shape *cuboidPtr = new Cuboid("Cuboid");
	cuboidPtr->addShape(rectangle1);
	cuboidPtr->addShape(rectangle2);
	cuboidPtr->addShape(rectangle3);

	cout <<cubePtr->getName() << ":" << cubePtr->getLength()<<"," << cubePtr->getBreadth() << "," << cubePtr->getArea() << "," << cubePtr->getPerimter() <<endl;
	cout <<cuboidPtr->getName() << ":" << cuboidPtr->getLength()<<"," << cuboidPtr->getBreadth() << "," << cuboidPtr->getArea() << "," << cuboidPtr->getPerimter() <<endl;

	fstream file;
	file.open("data.txt");
	square1->write(file);
	rectangle1->write(file);
	rectangle2->write(file);
	rectangle3->write(file);
	cubePtr->write(file);
	cuboidPtr->write(file);

	file.close();
	file.open("data.txt");
	read(file);

}

void Handler::read(std::istream &in)
{
	string line ="";
	string::size_type position;

	for (line = ""; getline(in, line);)
	{
		if (!line.empty())
		{
			position = line.find('[');
			if (position == string::npos)
			{
				position = line.find(':');
				string name = line.substr(0,position);
				line.erase(0, position+1);
				position = line.find(',');
				int length = stoi(line.substr(0,position));
				line.erase(0, position+1);
				position = line.find(',');
				int breadth = stoi(line.substr(0,position));
				line.erase(0, position+1);

				Shape *shapesPtr = new Rectangle(name, length, breadth);
				shapes.push_back(shapesPtr);
			}
			else
			{
				string type = line.substr(0,position);
				cout << type <<endl;

				if ("Cube" == type)
				{
					Shape *ptr = new Cube(type);
					shapes.push_back(ptr);
				}
				if ("Cuboid" == type)
				{
					Shape *ptr = new Cuboid(type);
					shapes.push_back(ptr);
				}

			}

		}
	}

	for (auto itr = shapes.begin(); itr!= shapes.end(); itr++)
	{
		cout << (**itr) <<endl;
	}
}
