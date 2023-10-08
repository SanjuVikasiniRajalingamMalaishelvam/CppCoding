// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;
#include "CComplex.h"
// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "OperatorOverloading started." << endl << endl;
	CComplex c1;
	CComplex c2(1,3);
	CComplex c3(4);
	CComplex c4(c3);

	c1.print();
	c2.print();
	c3.print();
	c4.print();


	return 0;
}
