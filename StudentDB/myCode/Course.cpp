/*
 * Course.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

//standard header files
#include <iterator>
#include <iostream>
#include <map>

//project header files
#include "Course.h"
#include "string.h"

/**
 * Map for getting the major with a char of the major name as the key
 */
std::map<unsigned char, std::string> Course::majorById={
	                                                	{'E', "Embedded Systems"},
														{'A',"Automation"},
														{'C',"Communications"},
														{'P', "Power Engineering"}
																					};


/**
 * Parametrized constructor
 * @params: coursekey, title, major, credit points
 */
Course::Course(unsigned int courseKey, std::string title, std::string myMajor,
		float creditPoints): courseKey (courseKey), title (title),creditPoints (creditPoints)
{
	this->major= myMajor.front();

}
Course::~Course()
{

}


/**
 * Gets the course key
 * @param type: void
 */
unsigned int Course::getCourseKey() const
{

	return courseKey;

}

/**
 * Gets the course title
 * @param type : string
 */
const std::string Course::getTitle() const
{
	return title;
}

/**
 * Gets the major which has the corresponding course
 * Gives the major id as the key value and gets the major name
 */
const std::string Course::getMajor() const
{
	std::string m_major;

	auto indexMajor = majorById.find(major);
	if (indexMajor != majorById.end())
	{
		m_major=indexMajor->second;

	}

	return m_major;
}

/**
 * Gets the credit points for the course
 */
float Course::getCreditPoints() const
{
	return creditPoints;
}

/**
 * Prints the course details and is of virtual void
 * In turn the course details of its derived classes are printed
 */
void Course::printCourse() const
{
	std::cout<<"Course key:    "<<courseKey<<std::endl;
	std::cout<<"Course Title:  "<<title<<std::endl;
	std::cout<<"Major:         "<<getMajor()<<std::endl;
	std::cout<<"Credit Points: "<<creditPoints<<std::endl;
}

/**
 * Writes all the course details to the file
 * In turn the course details of its derived classes are written to the file
 */
void Course::write(std::ostream &out) const
{
	out<<courseKey<<";"<<title<<";"<<getMajor()<<";"<<creditPoints;
}
