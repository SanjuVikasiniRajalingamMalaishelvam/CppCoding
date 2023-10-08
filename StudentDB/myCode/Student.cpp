/*
 * Student.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */


//Project header file
#include "Student.h"

//Standard header files
#include <iostream>
#include <string>

unsigned int Student::nextMatrikelNumber =  100000;


/**
 * Parametrized student constructor
 * The data from Student DB are passed as parameters to the student constructor
 */
Student::Student(std::string firstName,std::string lastName,Poco::Data::Date dateOfBirth,std::string street,
		std::string cityName,unsigned short postalCode,std::string additionalInfo):
		        																																																																																		   firstName(firstName), lastName(lastName)
{
	matrikelNumber =nextMatrikelNumber++;
	address= new Address(street,cityName, postalCode, additionalInfo);
	this->dateOfBirth = dateOfBirth;
}
Student::~Student()
{
}

/**
 * Gets the student first name
 */
std::string Student::getFirstName()
{
	return firstName;
}


/**
 * Gets the student last name
 */
std::string Student::getLastName()
{
	return lastName;
}


/**
 * Gets the student data of birth
 */
const Poco::Data::Date Student::getDateOfBirth() const
{
	return dateOfBirth;
}


/**
 * Gets the student matrikel number
 */
int Student::getMatrikelNumber()
{

	return matrikelNumber;
}


/**
 *Gets the enrollment details about student and course
 *Is a vector
 */
const std::vector<Enrollment>& Student::getEnrollment() const
{
	return enrollment;
}


/**
 * Gets the address details of the student
 */
Address* Student::getAddress()
{
	return address;
}


/**
 * Gets the address details as parameters
 * Creates an object new of Address and sets the details
 */
void Student::setAddress(std::string street, std::string cityName, unsigned short postalCode, std::string additionalInfo) //const checkkkkkkkkkkkkkkk
{
	this->address = new Address(street, cityName, postalCode, additionalInfo);
}

/**
 * Sets the date of birth of the student
 * Gets the poco DOB data
 */
void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

/**
 * Gets the details for the student enrollment and checks
 * Once checked, push backs the enrollment ddetails to the vector
 */
void Student::setEnrollment(std::string semester, const Course* course, float grade)
{
	Enrollment enrollStudent {semester, course, grade};

	if(checkEnrollment(enrollStudent.getCourse()->getCourseKey()))
	{
		enrollment.push_back(enrollStudent);
		std::cout<<"**New Student Enrolled**"<<std::endl;
	}
}

/**
 * Sets the first name of the student
 */
void Student::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}

/**
 * Sets the last name of the student
 */
void Student::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}


/**
 * Checks if the enrollment already exists or new
 * Prints a warning message incase of alreasy existing
 * Returns a bool value to set the enrollment incase of new
 */
bool Student::checkEnrollment (unsigned int courseKey)
{
	std::vector<Enrollment>::iterator itr;
	bool returnVal=true;
	for(itr = enrollment.begin(); itr != enrollment.end(); itr++)
	{
		if (itr->getCourse()->getCourseKey() == courseKey)
		{
			std::cout<<"**Already exists. Cannot enroll**"<<std::endl;
			returnVal=false; // Checkkkk
		}
		else
			returnVal=true;
	}

	return returnVal;
}

/**
 * Sets the matrikel number
 */
void Student::setMatrikelNumber(unsigned int matrikelNumber)
{
	this->matrikelNumber = matrikelNumber;
}

/**
 * Writes the student details to the file such as
 * first name
 * last name
 * matrikel number and dob
 */
void Student::write(std::ostream &out) const
{
	out<<matrikelNumber<<";"<<lastName<<";"<<firstName<<";"<<this->getDateOfBirth().day()<<"."<<
			this->getDateOfBirth().month()<<"."<<this->getDateOfBirth().year()<<";";

}

/**
 * Writes the enrollment details for the corresponding matrikel number
 */
void Student::printEnrollment(std::ostream &out) const
{
	std::vector<Enrollment>::const_iterator itr;
	for (itr=enrollment.begin(); itr!=enrollment.end(); itr++)
	{
		out<<matrikelNumber<<";"<<itr->getCourse()->getCourseKey()<<";"<<itr->getSemester()<<";"<<itr->getGrade()<<std::endl;
	}
}


/**
 * Prints all the courses enrolled by the student
 * After getting the matrikel number from Student DB
 */
void Student::printStudentEnroll()
{
	std::cout<<"COURSES ENROLLED"<<std::endl;
	std::vector<Enrollment>::const_iterator itr;
	for (itr=enrollment.begin(); itr!=enrollment.end(); itr++)
	{
		itr->getCourse()->printCourse();
		std::cout<<"Grade:"<<itr->getGrade()<<std::endl;
	}
}

/**
 * Checks if the course key is valid and is already existing in the vector
 * If yes, upgrades the grade points
 */
void Student::updateEnrollment(unsigned int course_Key,float gradePoints)
{
	std::vector<Enrollment>::iterator itr;
	for(itr = enrollment.begin(); itr != enrollment.end(); itr++)
	{
		if (itr->getCourse()->getCourseKey() == course_Key)
		{
			itr->setGrade(gradePoints);
			break;
		}

		else
			std::cout<<"**No Matching Course Key**"<<std::endl;
	}

}

/**
 * Checks if the course key is existing and valid
 * If yes, removes the corresponding enrollment
 */
void Student::deleteEnrollment(unsigned int course_Key, unsigned int matrikelNo)
{
	std::vector<Enrollment>::iterator itr;
	for(itr = enrollment.begin(); itr != enrollment.end(); itr++)
	{
		if (itr->getCourse()->getCourseKey() == course_Key)
		{
			enrollment.erase(itr);
			break;
		}
	}
}
