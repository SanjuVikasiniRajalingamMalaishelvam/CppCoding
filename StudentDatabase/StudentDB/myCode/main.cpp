// Standard (system) header files
#include <iostream>
#include <cstdlib>


using namespace std;

//project's header files here


#include "Course.h"
#include "SimpleUI.h"

/**
 * Main program
 * The complete Student Database starts with the execution of the run method
 * Contains only the run() method of the Simple UI class
 * Has a while loop to request for commands from the user continuously
 */
int main ()
{
	cout << "STUDENT DATABASE" << endl << endl;

	StudentDB db1;

	SimpleUI v1(db1);
	while(1)
	{
	v1.run();
	}

	return 0;
}
