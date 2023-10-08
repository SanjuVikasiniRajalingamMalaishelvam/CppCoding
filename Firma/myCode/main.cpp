// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include <fstream>
// Add more standard header files as required
// #include <string>
#include "Manager.h"
#include "Developer.h"
#include "Project.h"
#include "Assignee.h"
#include "FirmaDB.h"

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here

	Poco::Data::Date dob;
	dob.assign(1999, 10, 11);

	Employee *man = new Manager ("VIKASINI", 1,"sanjuvikasini@gmail.com", dob, 750000, 40, 2);
	Employee *dev1 = new Developer("SANJU", 2,"sanjuvikasini@gmail.com", dob, 750000, 40);
	Employee *dev2 = new Developer("SANJUVIKASINI", 3,"sanjuvikasini@gmail.com", dob, 750000, 40);


	cout << "......Hellooo........." <<endl;
	cout << man->getEmployeeID() <<endl;
	cout << dev2->getEmployeeID() <<endl;

//	dev2 = std::move(dev1);
	dev2 = dev1;
	cout << "..............." <<endl;
	cout << dev2->getEmployeeID();
//	cout << manager1 <<endl;
//	cout << dev1 <<endl;
//	cout << dev2 <<endl;

	Poco::Data::Date start;
	start.assign(2023, 1, 1);
	Poco::Data::Date end;
	end.assign(2023, 1, 5);


	Project project ("MadamVikasini", 5, start, end);


	FirmaDB db;
	db.addProject(&project);
//	db.addEmployee(man);
//	db.addEmployee(dev2);
//	db.addEmployee(dev1);
	db.assignEmployeeToProject("MadamVikasini", 1, 20);
	db.assignEmployeeToProject("MadamVikasini", 2, 30);
	db.assignEmployeeToProject("MadamVikasini", 3, 40);

	db.print();

//	FirmaDB db1;
//	db1 = db;

	fstream file;
	file.open("Frima.json");
	db.write(file);
	file.close();
	file.open("Frima.json");
	//db.read(file);
	cout << "hello read" <<endl;
	//file.close();



	return 0;
}
