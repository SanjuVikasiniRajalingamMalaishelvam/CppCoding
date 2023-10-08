/*
 * WeeklyCourse.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

//Project's header file
#include "Course.h"

//Standard header files
#include "Poco/DateTime.h"
#include "Poco/Data/Time.h"
#include <iostream>


/**
 * Class Weekly course is the inherited class from the base class Course
 * Contains all the details of the Weekly courses
 */
class WeeklyCourse: public Course {
private:
	Poco::DateTime::DaysOfWeek dayOfWeek;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;

public:

	/**
	 * Parametrized constructor of Weekly course
	 */
	WeeklyCourse(unsigned int courseKey,std::string title, std::string myMajor, float creditPoints, Poco::DateTime::DaysOfWeek dayOfWeek,
			       Poco::Data::Time startTime, Poco::Data::Time endTime);
	~WeeklyCourse();

	/**
	 * Gets the day of week of the weekly course
	 * Type Poco
	 */
	Poco::DateTime::DaysOfWeek getDayOfWeek() const;

	/**
	 * Gets the Weekly course end time
	 */
	const Poco::Data::Time& getEndTime() const;

	/**
	 * Gets the Weekly course start time
	 */
	const Poco::Data::Time& getStartTime() const;

	/**
	 * Prints all the details of the weekly courses
	 */
    void printCourse()const;

    /**
     * Writes the details of all the weekly courses to the file
     */
    void write(std::ostream& out)const;
};

#endif /* WEEKLYCOURSE_H_ */
