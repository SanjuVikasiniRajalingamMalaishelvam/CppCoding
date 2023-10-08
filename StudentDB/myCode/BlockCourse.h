/*
 * BlockCourse.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

//Project's header file
#include "Course.h"

//Standard header files
#include "Poco/Data/Time.h"
#include "Poco/Data/Date.h"
#include <iostream>

/**
 * Block Course is a derived class of the base class Course
 * Contains all the details of every Block courses
 */
class BlockCourse : public Course {
private:
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
public:

	/**
	 * Parametrized constructor of Block Course
	 */
	BlockCourse (unsigned int courseKey,std::string title, std::string myMajor, float creditPoints, Poco::Data::Date startDate,
			Poco::Data::Date endDate, Poco::Data::Time startTime, Poco::Data::Time endTime);
	~BlockCourse();

	/**
	 * Gets the block course start date
	 */
	const Poco::Data::Date& getStartDate() const;

	/**
	 * Gets the block course end date
	 */
	const Poco::Data::Date& getEndDate() const;

	/**
	 * Gets the block course start time
	 */
	const Poco::Data::Time& getStartTime() const;

	/**
	 * Gets the block course end time
	 */
	const Poco::Data::Time& getEndTime() const;

	/**
	 * Method to print the details of all block courses
	 */
	void printCourse()const;

	/**
	 * Method to write the details of all block courses to the file
	 */
	void write(std::ostream& out)const;
};

#endif /* BLOCKCOURSE_H_ */
