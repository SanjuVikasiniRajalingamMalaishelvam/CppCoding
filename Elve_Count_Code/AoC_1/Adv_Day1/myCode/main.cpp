// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

#include "CDay1.h"
using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Adv_Day1 started." << endl << endl;

	CDay1 obj;

	std::ifstream myFile;
	std::string fileName;
	cout << "Please enter the file name to open:" <<endl;
	std::cin >> fileName;
	myFile.open(fileName);

	obj.readData(myFile);
	obj.calculateCalories();

	return 0;
}
