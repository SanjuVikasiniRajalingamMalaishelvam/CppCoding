/*
 * SimpleUI.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */


//Project header file
#include "SimpleUI.h"

//Standard header files
#include <iostream>
#include <fstream>

/**
 * Parametrized constructor with the initialization of the object db
 */
SimpleUI::SimpleUI(StudentDB& db)
{
	myDB= &db;

}

// Destructor
SimpleUI::~SimpleUI()
{

}

/**
 * Method run() contains all the different commands to access Student Database
 * Gets the user input to choose of the available commands
 * The different switch cases call the respective methods and
 * execute the command
 */
void SimpleUI::run()
{
	int option;

	std::cout<<"****CHOOSE A COMMAND TO EXECUTE****"<<std::endl;
	std::cout<<"1-->Add New Course"<<std::endl;
	std::cout<<"2-->List Courses"<<std::endl;
	std::cout<<"3-->Add New Student"<<std::endl;
	std::cout<<"4-->Add Enrollment"<<std::endl;
	std::cout<<"5-->Print Student"<<std::endl;
	std::cout<<"6-->Search Student"<<std::endl;
	std::cout<<"7-->Update Student"<<std::endl;
	std::cout<<"8-->Writing the data to a file"<<std::endl;
	std::cout<<"9-->Reading the data from a file"<<std::endl;
	std::cout<<"10-->Client Access"<<std::endl;
	std::cout<<"****************************************************"<<std::endl;


	std::cin>>option;
	std::cout<<"----------------------------------------------------------"<<std::endl;
	switch (option)
	{
	case 1:
		myDB->addNewCourse();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	case 2:
		myDB->listCourses();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	case 3:
		myDB->addNewStudent();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	case 4:
		myDB->addEnrollment();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	case 5:
		myDB->printStudent();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	case 6:
		myDB->searchStudent();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	case 7:
		myDB->updateStudent();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	case 8:
	{
		std::ofstream myFile;
		std::string fileName;
		std::cout<<"Enter a file Name"<<std::endl;
		std::cin>>fileName;
		myFile.open(fileName);
		myDB->writeToFile(myFile);
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	}
	case 9:
	{
		std::ifstream myFile;
		std::string fileName;
		std::cout<<"Enter a file Name"<<std::endl;
		std::cin>>fileName;
		myFile.open(fileName);

		myDB->readFromFile(myFile);
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	}
	case 10:
	{
		myDB->clientAccess();
		std::cout<<"----------------------------------------------------------"<<std::endl;
		break;
	}
	default:
		std::cout<<"Enter a valid input again"<<std::endl;
		std::cout<<"----------------------------------------------------------"<<std::endl;

	}

}
