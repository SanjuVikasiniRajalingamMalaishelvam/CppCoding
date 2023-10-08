// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include <fstream>
#include <map>

using namespace std;
#include "ResistorPart.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "ResistorReader.h"


// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	// Testcases 1

	ResistorPart resistor ("R1", 42, 5);
	cout <<resistor<<endl;

	//Testcases 2 - Serial
	SerialResistorConnection serial ("R2");
	std::shared_ptr<Resistor> r3 = std::shared_ptr<Resistor>(new ResistorPart("R3", 1000, 10));
	std::shared_ptr<Resistor> r4 = std::shared_ptr<Resistor>(new ResistorPart("R3", 4700, 10));

	serial += r3;
	serial += r4;

	cout << serial.getName() << "=" << serial.nominalValue() << "Ohm" <<endl;

	//Testcases 2 - Parallel
	ParallelResistorConnection parallel ("R5");
	std::shared_ptr<Resistor> r6 = std::shared_ptr<Resistor>(new ResistorPart("R6", 1000, 10));
	std::shared_ptr<Resistor> r7 = std::shared_ptr<Resistor>(new ResistorPart("R7", 4700, 10));

	parallel += r6;
	parallel += r7;

	cout << parallel.getName() << "=" << parallel.nominalValue() << "Ohm" <<endl;


	fstream file;
	file.open("data.txt");
	serial.write(file);
	parallel.write(file);
	file.close();
	file.open("data.txt");

	std::map<std::string, ResisPtr> found;
	ResistorReader reader;
	reader.read(file, found);

	for (auto itr = found.begin(); itr!= found.end(); itr++)
	{
		cout << "hello" <<endl;
		cout << itr->first;
		cout << itr->second.get()->toString() <<endl;
	}





	return 0;
}
