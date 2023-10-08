// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
//#include "Shape.h"
//#include "Rectangle.h"
//#include "Cube.h"
//#include "Cuboid.h"

#include "Handler.h"

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
//    Shape *square1 = new Rectangle("square1", 10, 10);
//    Shape *rectangle1 = new Rectangle("rectangle1", 10, 15);
//
//    cout << *square1 <<endl;
//    cout << *rectangle1 <<endl;
//
//    Shape *rectangle2 = new Rectangle("rectangle2", 15, 5);
//    Shape *rectangle3 = new Rectangle("rectangle3", 10, 5);
//
//    cout << *rectangle2 <<endl;
//    cout << *rectangle3 <<endl;
//
//    Shape *cubePtr = new Cube("Cube");
//    cubePtr->addShape(square1);
//
//    Shape *cuboidPtr = new Cube("Cuboid");
//    cuboidPtr->addShape(rectangle1);
//    cuboidPtr->addShape(rectangle2);
//    cuboidPtr->addShape(rectangle3);

	Handler handlerObj;
	handlerObj.run();

	return 0;
}
