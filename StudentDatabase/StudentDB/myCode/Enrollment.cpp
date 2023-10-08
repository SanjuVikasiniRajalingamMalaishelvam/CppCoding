/*
 * Enrollment.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#include "Enrollment.h"

Enrollment::Enrollment(std::string semster, const Course *course, float grade):
                        semester(semster),course(course)
{
	this->grade=0.0;
}

const Course* Enrollment::getCourse() const
{
	return course;
}

float Enrollment::getGrade() const
{
	return grade;
}

const std::string Enrollment::getSemester() const
{
	return semester;
}

void Enrollment::setGrade(float gradePoints)
{
	this->grade=gradePoints;
}
