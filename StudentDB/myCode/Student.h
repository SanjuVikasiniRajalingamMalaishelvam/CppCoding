/*
 * Student.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef STUDENT_H_
#define STUDENT_H_


//Standard header files
#include <vector>
#include <algorithm>
#include "Poco/Data/Date.h"

//Project's header files
#include "Address.h"
#include "Enrollment.h"



/**
 *\brief Class Student contains all the details of the students including their address
 *\n Passes address details to the address class that is in composition
 *Contains the vector enrollment in which the students enrollment in courses are stored
 *Contains the static data of matriculation number
 */
class Student
{
private:
	static unsigned int nextMatrikelNumber;

	unsigned int matrikelNumber;
	std::string firstName;
	std::string lastName;
	Poco::Data::Date dateOfBirth;
	std::vector<Enrollment> enrollment;    // no in between insertion. just enroll or delete. so vector(composition)
	Address *address; //composition

public:

	/**
	 * Parametrized constructor of student
	 */
	Student(std::string firstName, std::string lastName,Poco::Data::Date dateOfBirth, std::string street, std::string cityName,unsigned short postalCode,std::string additionalInfo);
	virtual ~Student();

	/**
	 *Method to get the student first name
	 */
	std::string getFirstName();

	/**
	 * Method to get the student last name
	 */
	std::string getLastName();

	/**
	 * Method to get the student date of birth
	 */
	const Poco::Data::Date getDateOfBirth() const;

	/**
	 * Method to get the student matrikel number
	 */
	int getMatrikelNumber();

	/*
	 * Method to get the enrollment details of the student from the vector
	 */
	const std::vector<Enrollment>& getEnrollment() const;

	/**
	 * Method to get student address details from the Address class
	 */
	Address* getAddress();

	/**
	 * Method to check if the enrollment exists already
	 */
	bool checkEnrollment(unsigned int courseKey);

	/**
	 * Method to set the address details to the Address class
	 */
	void setAddress(std::string street, std::string cityName, unsigned short postalCode, std::string additionalInfo); //const checkkkkkkkkkkkkkkk

	/**
	 * Method to set the date of birth of the student
	 */
	void setDateOfBirth(const Poco::Data::Date &dateOfBirth);

	/**
	 * Method to set the enrollment of the student
	 */
	void setEnrollment (std::string semester, const Course* course, float grade);

	/**
	 * Method to set the first name of the student
	 */
	void setFirstName(const std::string &firstName);

	/**
	 * Method to set the last name of the student
	 */
	void setLastName(const std::string &lastName);

	/**
	 * Method to set the matrikel number
	 */
	void setMatrikelNumber(unsigned int matrikelNumber);

	/**
	 * Method to write the data to file
	 */
	virtual void write(std::ostream& out)const;

	/**
	 * Method to write the enrollment details
	 */
	void printEnrollment(std::ostream& out)const;

	/**
	 * Method to print the enrolled courses of the student
	 */
	void printStudentEnroll();

	/**
	 * Method to upgrade grade for the student
	 */
	void updateEnrollment(unsigned int course_Key, float gradePoints);

	/**
	 * Method to remove an enrollment
	 */
	void deleteEnrollment(unsigned int course_Key, unsigned int matrikelNo);

	static unsigned int getNextMatrikelNumber()
	{
		return nextMatrikelNumber;
	}

	static void setNextMatrikelNumber(unsigned int nextMatrikelNumber)
	{
		Student::nextMatrikelNumber = nextMatrikelNumber;
	}
};

#endif /* STUDENT_H_ */
