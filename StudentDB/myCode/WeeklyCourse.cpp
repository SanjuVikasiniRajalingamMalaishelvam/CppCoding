/*
 * WeeklyCourse.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */


//Project's header files
#include "WeeklyCourse.h"


/**
 * Parametrized constructor of Weekly course
 */
WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
		std::string myMajor, float creditPoints,Poco::DateTime::DaysOfWeek dayOfWeek,
		Poco::Data::Time startTime, Poco::Data::Time endTime):
		Course{courseKey, title, myMajor, creditPoints},dayOfWeek(dayOfWeek),startTime(startTime), endTime(endTime)
{


}

/**
* Gets the day of week when the weekly course takes place
*/
Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{

	return dayOfWeek;
}

/**
 * Gets the course end time
 */
const Poco::Data::Time& WeeklyCourse::getEndTime() const
{

	return endTime;
}

WeeklyCourse::~WeeklyCourse()
{
}

/**
 * Gets the course start time
 */
const Poco::Data::Time& WeeklyCourse::getStartTime() const
{
	return startTime;
}

/**
 * Prints all the weekly courses details
 */
void WeeklyCourse::printCourse()const
{
	std::cout<<"***COURSE TYPE: W***"<<std::endl;
	Course::printCourse();
	std::cout<<"Weekly Course Day of the Week:  "<<this->getDayOfWeek()<<std::endl;
	std::cout<<"Weekly Course Start Time: Hours "<<this->getStartTime().hour()<<"Minutes: "<<this->getStartTime().minute()
																							<<"Second: "<<this->getStartTime().second()<<std::endl;
	std::cout<<"Weekly Course End Time:"<<this->getEndTime().hour()<<"Minutes:"<<this->getEndTime().minute()
																									<<"Second:"<<this->getEndTime().second()<<std::endl;
}

/**
 * Writes all the weekly courses details to the file
 */
void WeeklyCourse::write(std::ostream &out)const
{
	out<<"W"<<";";
	Course::write(out);
	out<<";"<<this->getDayOfWeek()<<";"<<this->getStartTime().hour()<<":"<<this->getStartTime().minute()<<
			":"<<this->getStartTime().second()<<";"<<this->getEndTime().hour()<<":"<<this->getEndTime().minute()<<
			":"<<this->getEndTime().second()<<std::endl;

}
