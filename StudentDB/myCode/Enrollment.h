/*
 * Enrollment.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include "Course.h"
class Enrollment
{
private:
	std::string semester;
	const Course* course;
	float grade;



public:
	Enrollment(std::string semester, const Course* course, float grade); //the values in a vector will move and address will change. so using a pointer
	//const Course*& getCourse() const; //pointer by ref--> attribute is an obj. so avoid unnecessary copy
	const Course* getCourse() const;
	float getGrade() const;
	void setGrade(float gradePoints);
	const std::string getSemester() const;
};

#endif /* ENROLLMENT_H_ */
