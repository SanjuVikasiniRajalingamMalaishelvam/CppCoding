/*
 * Course.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef COURSE_H_
#define COURSE_H_

//standard header files
#include <string>
#include<map>
#include "Poco/DateTime.h"
#include "Poco/Data/Time.h"
#include "Poco/Data/Date.h"

/**
 * Class course which is of relationship Inheritance
 * Is a base class that contains two derived classes - Weekly and Blocked
 * Contains a static map for Major id
 */
class Course
{
private:
	static std::map<unsigned char, std::string> majorById;
	unsigned int courseKey;
	std::string title;
	float creditPoints;
	unsigned char major;

public:

	/**
	 * Parametrized constructor of course
	 */
	Course(unsigned int courseKey,std::string title, std::string myMajor, float creditPoints);
	virtual ~Course()=0;

	/**
	 *Gets the course key of the corresponding course
	 */
	unsigned int getCourseKey() const;

	/**
	 * Gets the course title
	 */
	const std:: string getTitle() const;

	/**
	 * Gets the major for which the course is created
	 */
	const std:: string getMajor() const;

	/**
	 * Gets the credit points allocated for the course
	 */
	float getCreditPoints() const;

	/**
	 * Prints the courses stored in the student database
	 */
	virtual void printCourse()const;

	/**
	 * Method to write the course details and enrolled courses to the file
	 */
	virtual void write(std::ostream& out)const;

};


#endif /* COURSE_H_ */
