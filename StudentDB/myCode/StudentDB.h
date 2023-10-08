/*
 * StudentDB.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_


/**
 * Project header files
 * Header files to access Poco Library
 * To access course and its derived classes
 * To access the student class
 */
#include <map>
#include <memory>
#include <string>
#include "Poco/DateTime.h"
#include "Poco/Data/Time.h"
#include "Poco/Data/Date.h"
#include "Student.h"
#include "Course.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"

/**
 * \brief Class StudentDb executes the commands requested by the user
 *\n Student DB class will contain the map for storing Student data
 *\n and also to the courses list data
 *\n The map for courses is a unique pointer
 */
class StudentDB
{
private:
	std::map<int, Student> students;
	std::map<int, std::unique_ptr<const Course>> courses;


public:
	StudentDB();
	virtual ~StudentDB();

	/**
	 *Method to add new course to the Course list in student DB
	 *
	 */
	void addNewCourse();
	/**
	 * Lists all the courses with their details that are in the database
	 */
	void listCourses();
	/**
	 * Adds new student and their details to the map in Student DB
	 */
	void addNewStudent();
	/**
	 * Enrolls each student to the respective course
	 */
	void addEnrollment();
	/**
	 * Prints all the student details with the courses they are enrolled in
	 */
	void printStudent();
	/**
	 * Gives the details of the student searched by the user
	 */
	void searchStudent();
	/**
	 * Updates the details of the students including their enrollment and details
	 */
	void updateStudent();
	/**
	 * Writes all the details in the student DB to the file
	 */
	void writeToFile(std::ostream& out);
	/**
	 * Reads all the details from the file and store it back to the student DB
	 */
	void readFromFile(std::istream& in);
	/**
	 * Method to store details to the student map after reading from the file
	 */
	void readAddStudent(int checkNo,std::string firstName,std::string lastName,unsigned int dobDay,unsigned int dobMonth,
			unsigned int dobYear,std::string streetName,std::string cityName,unsigned short postalCode,std::string additionalInfo);
	/**
	 * Method to store details to the course map after reading from the file
	 */
	void readAddCourse(int courseKey, std::string courseTitle, unsigned char courseType, std::string major, float creditPoints,
			int dayOfWeek,int startDate, int startMonth, int startYear, int endDate, int endMonth, int endYear,
			int startTimeHour, int startTimeMinute,int startTimeSecond,int endTimeHour, int endTimeMinute, int endTimeSecond);
	/**
	 * Method to store back the enrollment details after reading from the file
	 */
	void readAddEnrollment(int checkNo,std::string semester,int courseKey,float grade);
	/**
	 * Access the server and fetches the student details and store in student DB
	 */
	void clientAccess();




};

#endif /* STUDENTDB_H_ */
