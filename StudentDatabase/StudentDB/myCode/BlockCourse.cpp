/*
 * BlockCourse.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

//project's header file
#include "BlockCourse.h"

/**
 * Parametrized constructor of Block course
 */
BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
	std::string myMajor, float creditPoints, Poco::Data::Date startDate,
	Poco::Data::Date endDate, Poco::Data::Time startTime,
	Poco::Data::Time endTime):Course{courseKey, title, myMajor, creditPoints}, startDate(startDate),
	endDate(endDate),startTime(startTime),endTime(endTime)
{

}

BlockCourse::~BlockCourse()
{

}

/**
 * Gets the End date of the block course
 */
const Poco::Data::Date& BlockCourse::getEndDate() const
{
	return this->endDate;
}

/**
 * Gets the End time of the block course
 */
const Poco::Data::Time& BlockCourse::getEndTime() const
{
	return this->endTime;
}

/**
 * Gets the start date of the block course
 */
const Poco::Data::Date& BlockCourse::getStartDate() const
{
	return this->startDate;
}

/**
 * Gets the start time of the block course
 */
const Poco::Data::Time& BlockCourse::getStartTime() const
{
	return this->startTime;
}

/**
 * Prints all the block course details
 * Method is called when the virtual type in Course class is called
 */
void BlockCourse::printCourse()const
{
	std::cout<<"***COURSE TYPE: B***"<<std::endl;
	Course::printCourse();
	std::cout<<"Block Course Start Date: "<<this->getStartDate().day()<<"/"<<this->getStartDate().month()<<"/"
			<<this->getStartDate().year()<<std::endl;
	std::cout<<"Block Course End Date:   "<<this->getEndDate().day()<<"/"<<this->getEndDate().month()<<"/"
			<<this->getEndDate().year()<<std::endl;
	std::cout<<"Block Course Start Time: Hours "<<this->getStartTime().hour()<<"Minutes: "<<this->getStartTime().minute()
			<<"Second: "<<this->getStartTime().second()<<std::endl;
	std::cout<<"Block Course End Time:   "<<this->getEndTime().hour()<<"Minutes:"<<this->getEndTime().minute()
					<<"Second:"<<this->getEndTime().second()<<std::endl;
}


/**
 * Method to write all the block course details to the file
 */
void BlockCourse::write(std::ostream &out) const
{

	out<<"B"<<";";
	Course::write(out);
	out<<";"<<this->getStartDate().day()<<"."<<this->getStartDate().month()<<"."<<this->getStartDate().year()<<
			";"<<this->getEndDate().day()<<"."<<this->getEndDate().month()<<"."<<this->getEndDate().year()<<
			";"<<this->getStartTime().hour()<<":"<<this->getStartTime().minute()<<":"<<this->getStartTime().second()<<
			";"<<this->getEndTime().hour()<<":"<<this->getEndTime().minute()<<":"<<this->getEndTime().second()<<std::endl;
}
