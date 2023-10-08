/*
 * StudentDB.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

//Project's header file
#include "StudentDB.h"

//Standard header files
#include <iostream>
#include <string>
#include <utility> // for pair in map
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/JSON/Object.h"
#include "Poco/StreamCopier.h"
#include"Poco/JSON/Parser.h"


/**
 * Student DB default constructor
 */
StudentDB::StudentDB()
{


}


StudentDB::~StudentDB()
{

}

/**
 * Fetches the different details about the course like
 * course key and course title
 * major and credit points
 * Categorizes the type of course into Weekly and blocked
 * Store the course details in the course map of Student DB
 */
void StudentDB::addNewCourse()
{
	unsigned char courseType;
	unsigned int courseKey;
	std::string title;
	std::string myMajor;
	float creditPoints;
	unsigned int day_of_week;
	int hours, minutes, seconds;
	int date, month, year;
	Poco::DateTime::DaysOfWeek dayOfWeek;        //weekly
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	Poco::Data::Date startDate;                  //block
	Poco::Data::Date endDate;


	std::cout<<"Enter the Course key : "<<std::endl;
	std::cin>>courseKey;

	std::cout<<"Enter the course title : "<<std::endl;
	std::cin.ignore();
	std::getline(std::cin,title);

	std::cout<<"Enter the major :"<<std::endl;
	std::cin.ignore(0);
	std::getline(std::cin,myMajor);

	std::cout<<"Enter the credit points :"<<std::endl;
	std::cin>>creditPoints;

	std::cout<<"Enter the course type: Weekly or Block"<<std::endl;
	std::cout<<"Enter W for Weekly Course and B for Block Course"<<std::endl;
	std::cin>>courseType;


	if (courseType=='W')
	{
		std::cout<<"Enter a number to select day of weekly Course:"<<std::endl;
		std::cout<<"0-Sunday, 1- Monday, 2- Tuesday, 3-Wednesday"<<std::endl;
		std::cout<<"4-Thursday, 5-Friday, 6-Saturday" <<std::endl;
		std::cin>>day_of_week;
		dayOfWeek= Poco::DateTime::DaysOfWeek(day_of_week);

		std::cout<<"Enter the Course start time (hours/minutes/seconds)"<<std::endl;
		std::cin>>hours;
		std::cin>>minutes;
		std::cin>>seconds;
		startTime.assign(hours, minutes, seconds);

		std::cout<<"Enter the Course end time (hours/minutes/seconds)"<<std::endl;
		std::cin>>hours;
		std::cin>>minutes;
		std::cin>>seconds;
		endTime.assign(hours, minutes, seconds);

		std::unique_ptr<const Course> addNewCourse = std::unique_ptr<const Course>(new WeeklyCourse(courseKey,title, myMajor,creditPoints,
				dayOfWeek, startTime, endTime));
		courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey, std::move(addNewCourse)));

	}

	if (courseType=='B')
	{
		std::cout<<"Enter the Course start time (hours/minutes/seconds)"<<std::endl;
		std::cin>>hours>>minutes>>seconds;
		startTime.assign(hours, minutes, seconds);

		std::cout<<"Enter the Course end time (hours/minutes/seconds)"<<std::endl;
		std::cin>>hours>>minutes>>seconds;
		endTime.assign(hours, minutes, seconds);

		std::cout<<"Enter the Course start date (year/month/date)"<<std::endl;
		std::cin>>year;
		std::cin>>month;
		std::cin>>date;
		startDate.assign(year, month, date);

		std::cout<<"Enter the Course end  date (year/month/date)"<<std::endl;
		std::cin>>year;
		std::cin>>month;
		std::cin>>date;
		endDate.assign(year, month, date);

		std::unique_ptr<const Course> addNewCourse = std::unique_ptr<const Course>(new BlockCourse(courseKey,title, myMajor,creditPoints,
				startDate, endDate,startTime, endTime));
		/**
		 * unique pointer can't make a copy.. if goes out of range, its deleted
		 */
		courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey, std::move(addNewCourse)));
	}

}


/**
 *Displays the number of courses in the Student DB
 *Prints all the courses in DB including weekly and blocked courses
 */
void StudentDB::listCourses()
{
	std::cout<<courses.size()<<std::endl;

	for (auto courseitr=courses.begin();courseitr!=courses.end();courseitr++)
	{
		courseitr->second.get()->printCourse();
	}
}


/**
 * Fetches the details of the student to be added to the database
 * Contains poco functions for Date of birth
 * Fetches the details of the address of student and insert to the
 * student map in Student Db
 */
void StudentDB::addNewStudent()
{
	std::string firstName;
	std::string lastName;
	Poco::Data::Date dateOfBirth;
	int date, month, year;
	unsigned short postalCode;
	std::string streetName;
	std::string cityName;
	std::string additionalInfo;

	std::cout<<"Enter Student first name :"<<std::endl;
	std::cin.ignore();
	std::getline(std::cin,firstName);

	std::cout<<"Enter Student last name :"<<std::endl;
	std::cout<<std::endl;
	std::cin.ignore(0);
	std::getline(std::cin,lastName);

	std::cout<<"Enter Student Date Of Birth (Year/Month/Date)"<<std::endl;
	std::cin>>year;
	std::cin>>month;
	std::cin>>date;
	dateOfBirth.assign(year, month, date);

	std::cout<<"Enter the following details for Address:"<<std::endl;
	std::cout<<"Street Name :"<<std::endl;
	std::cout<<std::endl;
	std::cin.ignore();
	std::getline(std::cin,streetName);

	std::cout<<"City Name :"<<std::endl;
	std::cout<<std::endl;
	std::cin.ignore(0);
	std::getline(std::cin,cityName);

	std::cout<<"Postal Code :"<<std::endl;
	std::cout<<std::endl;
	std::cin>>postalCode;

	std::cout<<"Additional Information :"<<std::endl;
	std::cin.ignore();
	std::getline(std::cin,additionalInfo);

	Student details{firstName, lastName, dateOfBirth, streetName,cityName, postalCode, additionalInfo};

	students.insert(std::make_pair(details.getMatrikelNumber(), details));
}


/**
 * Fetches the matrikel number of the respective student
 * and course key for which enrollment is to be done
 * If course key and matrikel number present in the Student Db, checks for previous enrollment
 * If no previous enrollments, new enrollment is done
 * Else prints a warning message for invalid details or enrollment already exists
 */
void StudentDB::addEnrollment()
{
	unsigned int matrikelNo, courseKey;
	std::string sem;
	float grade=0.0;

	std::cout<<"Enter the Student Matrikel Number"<<std::endl;
	std::cin>>matrikelNo;

	std::cout<<"Enter the course key"<<std::endl;
	std::cin>>courseKey;

	std::cout<<"Enter the semester in words "<<std::endl;
	std::cin.ignore();
	std::getline(std::cin, sem);


	std::map<int, Student>::iterator itr;
	std::map<int, std::unique_ptr<const Course>>::const_iterator courseitr;


	itr = students.find(matrikelNo);
	courseitr=courses.find(courseKey);

	if ((itr != students.end()) && (courseitr!= courses.end()))
	{
		std::cout<<"**VALID DETAILS**"<<std::endl;
		itr->second.setEnrollment(sem, courseitr->second.get(), grade);

	}

	else
	{
		std::cout<<"***INVALID***"<<std::endl;
		std::cout<<"SELECT ADD ENROLLMENT COMMAND AGAIN "<<std::endl;
	}
}


/**
 * Prints the details of all the students in the Student Database
 * Lists all the courses the student has enrolled in
 * Lists the address of the student along with the details
 * If no matrikel number is found in the database, prints not found
 */
void StudentDB::printStudent()
{
	unsigned int matrikelNo;

	std::cout<<"Enter a Matrikel Number to print student data"<<std::endl;
	std::cin>>matrikelNo;
	std::map<int, Student>::iterator itr;
	itr = students.find(matrikelNo);
	if(itr != students.end())
	{
		std::cout<<"First Name:"<<itr->second.getFirstName()<<std::endl;
		std::cout<<"Last Name:"<< itr->second.getLastName() << std::endl;
		std::cout<<"Date Of Birth:"<<"Year"<<"  "<<itr->second.getDateOfBirth().year()<<"Month"<<"   "<<
				itr->second.getDateOfBirth().month()<<"Day"<<"    "<<itr->second.getDateOfBirth().day()<<std::endl;
		std::cout<<"Street Name:"<<itr->second.getAddress()->getStreet()<<std::endl;
		std::cout<<"City Name:"<<itr->second.getAddress()->getCityName()<<std::endl;
		std::cout<<"Postal Code:"<<itr->second.getAddress()->getPostalCode()<<std::endl;
		std::cout<<"Additional Information:"<<itr->second.getAddress()->getAdditionalInfo()<<std::endl;
		itr->second.printStudentEnroll();
	}
	else
	{
		std::cout <<"not found"<<std::endl;
	}

}


/**
 * Queries the user for a string
 * If the string matches any student name in the database, prints the details
 * Student first name, last name and matrikel number
 */
void StudentDB::searchStudent()
{
	std::string nameStr="None";
	std::cout<<"Enter the Student name to search"<<std::endl;
	std::cin>>nameStr;
	std:: size_t searchFirstName;
	std::size_t searchLastName;

	std::map<int, Student>::iterator itr;
	for (itr=students.begin(); itr!=students.end(); itr++ )
	{
		searchFirstName= itr->second.getFirstName().find(nameStr);
		if (searchFirstName!=std::string::npos)
		{
			std::cout<<"Matrikel Number:    "<<itr->first<<std::endl;
			std::cout<<"Student First Name: "<<itr->second.getFirstName()<<std::endl;
			std::cout<<"Student Last Name:  "<<itr->second.getLastName()<<std::endl;
		}
		searchLastName= itr->second.getLastName().find(nameStr);
		if (searchLastName!=std::string::npos)
		{
			std::cout<<"Matrikel Number:    "<<itr->first<<std::endl;
			std::cout<<"Student First Name: "<<itr->second.getFirstName()<<std::endl;
			std::cout<<"Student Last Name:  "<<itr->second.getLastName()<<std::endl;
		}
	}
}


/**
 * Asks the user for a matrikel number
 * If the matrikel number is present, asks for details to be updated
 * In enrollment update, either enrollment can be removed
 * Or grade can be updated
 * Uses poco library for date of birth of the student
 */
void StudentDB::updateStudent()
{
	int matrikelNo;
	int option;
	int date, month, year;
	std::cout<<"Enter the Matrikel Number of the Student to update any information"<<std::endl;
	std::cin>>matrikelNo;
	std::map<int, Student>::iterator itr;
	itr = students.find(matrikelNo);
	if(itr != students.end())
	{
		std::cout<<"****Matrikel Number found. Press any one command to update****"<<std::endl;
		std::cout<<"1.Student First Name"<<std::endl;
		std::cout<<"2.Student Last Name"<<std::endl;
		std::cout<<"3.Date Of Birth"<<std::endl;
		std::cout<<"4.Address"<<std::endl;
		std::cout<<"5.Delete or Update Grade points"<<std::endl;
		std::cout<<"0.Terminate"<<std::endl;

		std::cout<<"**********************************************"<<std::endl;
		std::cin>>option;

		switch (option)
		{
		case 1:
		{
			std::string firstName;
			std::cout<<"Enter first Name to be updated"<<std::endl;
			std::cin.ignore();
			std::getline(std::cin,firstName);
			itr->second.setFirstName(firstName);
			break;

		}

		case 2:
		{
			std::string lastName;
			std::cout<<"Enter last Name to be updated"<<std::endl;
			std::cin.ignore();
			std::getline(std::cin,lastName);
			itr->second.setLastName(lastName);
			break;
		}
		case 3:
		{
			Poco::Data::Date dateOfBirth;
			std::cout<<"Enter date of birth to be updated (year/month/date)"<<std::endl;
			std::cin>>year;
			std::cin>>month;
			std::cin>>date;
			dateOfBirth.assign(year, month, date);
			itr->second.setDateOfBirth(dateOfBirth);
			break;
		}

		case 4:
		{
			std::string streetName, cityName, additionalInfo;
			unsigned short postalCode;
			std::cout<<"Enter the Address to be updated :"<<std::endl;
			std::cin.ignore();
			std::cout<<"Street Name"<<std::endl;
			std::getline(std::cin,streetName);
			std::cout<<"City Name"<<std::endl;
			std::cin.ignore(0);
			std::getline(std::cin,cityName);
			std::cout<<"PostalCode"<<std::endl;
			std::cin>>postalCode;
			std::cout<<"Additional Info"<<std::endl;
			std::cin.ignore();
			std::getline(std::cin,additionalInfo);
			for (itr = students.begin(); itr!=students.end(); itr++)
			{
				itr->second.setAddress(streetName, cityName, postalCode,additionalInfo);
			}
			break;
		}
		case 5:
		{
			unsigned int course_Key;
			float gradePoints, option;

			std::cout<<"Enter the Course Key"<<std::endl;
			std::cin>>course_Key;
			std::cout<<"Press 1 for update grades and 2 for  Removing enrollment "<<std::endl;
			std::cin>>option;

			if (option==1)
			{
				std::cout<<"Enter the grade points to be updated"<<std::endl;
				std::cin>>gradePoints;

				itr->second.updateEnrollment(course_Key, gradePoints);
				std::cout<<"**Student Enrollment Updated**"<<std::endl;
			}
			if (option ==2)
			{
				itr->second.deleteEnrollment(course_Key, matrikelNo);
				std::cout<<"**Student Enrollment Removed**"<<std::endl;
			}

			break;
		}
		case 0:
		{
			std::cout<<"**Terminated**"<<std::endl;
			break;

		}
		}
	}
}

/**
 * Writes the number of courses, students and enrollment in the database to file
 *Iterates through the student and course map and writes all the details to file
 *Also writes the enrollment details
 */
void StudentDB::writeToFile(std::ostream& out)
{

	out<<courses.size()<<std::endl;
	for (auto courseitr=courses.begin();courseitr!=courses.end();courseitr++)
	{
		courseitr->second.get()->write(out);
	}

	out<<students.size()<<std::endl;
	for (auto itr= students.begin(); itr!=students.end(); itr++)
	{
		itr->second.write(out);
		out<<itr->second.getAddress()->getStreet()<<";"<<itr->second.getAddress()->getPostalCode()<<";"
				<<itr->second.getAddress()->getCityName()<<";"<<itr->second.getAddress()->getAdditionalInfo()<<"\n";

	}

	int i=0;
	for(auto itr1 = students.begin(); itr1!=students.end();itr1++)
	{

		i+=itr1->second.getEnrollment().size();
	}
	out<<i<<std::endl;
	for (auto itr= students.begin(); itr!=students.end(); itr++)
	{
		itr->second.printEnrollment(out);
	}

}


/**
 * Reads all the data from the file
 * Converts to the respective types and store back to the empty student and course map in DB
 * Also adds the details of the student enrollment in respective courses
 */
void StudentDB::readFromFile(std::istream& in)
{
	courses.clear();
	students.clear();


	Student::setNextMatrikelNumber(100000);

	std::string line ="";
	std::string temp, checkSecond;
	unsigned char courseType;
	int courseKey;
	std::string courseTitle,major, semester;
	std::string lastName, firstName, streetName, cityName, additionalInfo;
	float creditPoints,grade;
	int dayOfWeek, dobDate, dobMonth, dobYear;
	int startTimeHour,startTimeMinute,startTimeSecond,endTimeHour,endTimeMinute,endTimeSecond;
	int startDate, startMonth, startYear, endDate, endMonth, endYear;
	unsigned short postalCode;
	int courseSize,studentSize,enrollmentSize,checkNo;


	std::getline(in, line);
	courseSize=atoi(line.c_str());
	for (int i=0; i<courseSize; i++)
	{
		std::getline(in, line);
		std::stringstream inputString(line);
		std::getline(inputString,temp, ';');
		courseType= temp[0];
		if (courseType=='W')
		{
			std::getline(inputString,temp, ';');
			courseKey= atoi(temp.c_str());
			std::getline(inputString,courseTitle, ';');
			std::getline(inputString,major, ';');
			std::getline(inputString,temp, ';');
			creditPoints= atof(temp.c_str());
			std::getline(inputString,temp, ';');
			dayOfWeek= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			startTimeHour= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			startTimeMinute= atoi(temp.c_str());
			std::getline(inputString,temp, ';');
			startTimeSecond= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			endTimeHour= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			endTimeMinute= atoi(temp.c_str());
			std::getline(inputString,temp, ';');
			endTimeSecond= atoi(temp.c_str());
			readAddCourse(courseKey, courseTitle, courseType, major, creditPoints, dayOfWeek, startDate, startMonth, startYear,
					endDate, endMonth, endYear, startTimeHour, startTimeMinute,startTimeSecond, endTimeHour, endTimeMinute, endTimeSecond);

		}
		else if (courseType=='B')
		{
			std::getline(inputString,temp, ';');
			courseKey= atoi(temp.c_str());
			std::getline(inputString,courseTitle, ';');
			std::getline(inputString,major, ';');
			std::getline(inputString,temp, ';');
			creditPoints= atof(temp.c_str());
			std::getline(inputString,temp, ':');
			startDate= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			startMonth= atoi(temp.c_str());
			std::getline(inputString,temp, ';');
			startYear= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			endDate= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			endMonth= atoi(temp.c_str());
			std::getline(inputString,temp, ';');
			endYear= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			startTimeHour= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			startTimeMinute= atoi(temp.c_str());
			std::getline(inputString,temp, ';');
			startTimeSecond= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			endTimeHour= atoi(temp.c_str());
			std::getline(inputString,temp, ':');
			endTimeMinute= atoi(temp.c_str());
			std::getline(inputString,temp, ';');
			endTimeSecond= atoi(temp.c_str());
			readAddCourse(courseKey, courseTitle, courseType, major, creditPoints, dayOfWeek, startDate, startMonth, startYear,
					endDate, endMonth, endYear, startTimeHour, startTimeMinute,startTimeSecond, endTimeHour, endTimeMinute, endTimeSecond);
		}
	}
	std::getline(in, line);
	studentSize=atoi(line.c_str());

	for (int i =0; i<studentSize; i++)
	{
		std::getline(in, line);
		std::stringstream inputString(line);
		std::getline(inputString, temp, ';');
		checkNo= atoi (temp.c_str());
		std::getline(inputString,lastName, ';');
		std::getline(inputString,firstName, ';');
		std::getline(inputString, temp, '.');
		dobDate=atoi(temp.c_str());
		std::getline(inputString, temp, '.');
		dobMonth=atoi(temp.c_str());
		std::getline(inputString, temp, ';');
		dobYear=atoi(temp.c_str());
		std::getline(inputString,streetName, ';');
		std::getline(inputString,temp, ';');
		postalCode= atoi(temp.c_str());
		std::getline(inputString, cityName,';');
		std::getline(inputString, additionalInfo, ';');


		readAddStudent(checkNo, firstName, lastName, dobDate, dobMonth, dobYear,streetName, cityName,  postalCode, additionalInfo);

	}

	std::getline(in, line);
	enrollmentSize=atoi(line.c_str());
	for (int i =0; i<enrollmentSize; i++)
	{
		std::getline(in, line);
		std::stringstream inputString(line);
		std::getline(inputString, temp, ';');
		checkNo= atoi (temp.c_str());
		std::getline(inputString,temp,';');
		courseKey=atoi(temp.c_str());
		std::getline(inputString, semester, ';');
		std::getline(inputString, temp, ';');
		grade=atof(temp.c_str());

		readAddEnrollment(checkNo,semester,courseKey, grade);

	}
}


/**
 * The students details read from the file are passed as paramaters
 * Details are added to the map again
 */
void StudentDB::readAddStudent(int checkNo, std::string firstName,std::string lastName, unsigned int dobDate,
		unsigned int dobMonth, unsigned int dobYear,std::string streetName,std::string cityName,unsigned short postalCode,std::string additionalInfo)
{
	Poco::Data::Date dateOfBirth;
	dateOfBirth.assign(dobYear, dobMonth, dobDate);

	Student details {firstName, lastName,dateOfBirth, streetName,cityName, postalCode, additionalInfo};
	details.setMatrikelNumber(checkNo);
	students.insert(std::make_pair(details.getMatrikelNumber(), details));

}


/**
 * Courses details fetched after reading from the file are passed as parameters
 * Details are added back to the course map in DB
 * Course type is also categorized
 */
void StudentDB::readAddCourse(int courseKey, std::string courseTitle, unsigned char courseType, std::string major, float creditPoints, int dayOfWeek,
		int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear,int startTimeHour, int startTimeMinute,
		int startTimeSecond,int endTimeHour, int endTimeMinute,int endTimeSecond)
{
	if (courseType=='W')
	{
		Poco::Data::Time startTime;
		Poco::Data::Time endTime;

		startTime.assign(startTimeHour, startTimeMinute, startTimeSecond);
		endTime.assign(endTimeHour, endTimeMinute, endTimeSecond);
		std::unique_ptr<const Course> addReadNewCourse = std::unique_ptr<const Course>(new WeeklyCourse(courseKey,courseTitle, major,creditPoints,
				(Poco::DateTime::DaysOfWeek)dayOfWeek, startTime, endTime));
		courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey, std::move(addReadNewCourse)));


	}
	if (courseType=='B')
	{
		Poco::Data::Time startTime;
		Poco::Data::Time endTime;
		Poco::Data::Date startDate;  //block
		Poco::Data::Date endDate;


		startTime.assign(startTimeHour, startTimeMinute, startTimeSecond);
		endTime.assign(endTimeHour, endTimeMinute, endTimeSecond);
		startDate.assign(startYear, startMonth, startDay);
		endDate.assign(endYear, endMonth, endDay);
		std::unique_ptr<const Course> addReadNewCourse = std::unique_ptr<const Course>(new BlockCourse(courseKey,courseTitle, major,creditPoints,
				startDate, endDate,startTime, endTime));
		courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey, std::move(addReadNewCourse)));

	}
}


/**
 * Enrollment details fetched after reading from the file are passed as parameters
 * Details are added to the database again
 */
void StudentDB::readAddEnrollment(int checkNo, std::string semester,int courseKey,float grade)
{
	std::map<int, Student>::iterator itr;
	std::map<int, std::unique_ptr<const Course>>::const_iterator courseitr;

	itr = students.find(checkNo);
	courseitr=courses.find(courseKey);

	if ((itr != students.end()) && (courseitr!= courses.end()))
	{

		itr->second.setEnrollment(semester, courseitr->second.get(), grade);

	}
}


/**
 * Access the server to fetch student details
 * Details are parsed for the corresponding number of students
 * After fetching the details, server is shutdown
 * Details fetched are written to the database
 */
void StudentDB::clientAccess()
{

	std::string line ="";

	std::cout<<"Enter the no of students data you want to receive"<<std::endl;
	int studentCount;
	std::cin>>studentCount;
	for (int count=0; count<studentCount; count++)
	{
		Poco::Net::SocketAddress s_adr("www.mnl.de", 4242);
		Poco::Net::StreamSocket socket(s_adr);
		Poco::Net::SocketStream str(socket);

		str<<"generate"<<std::endl;
		str.flush();

		socket.shutdownSend();

		std::getline(str, line);
		std::getline(str, line);


		socket.shutdownReceive();

		try {
			std::string json = line;
			Poco::JSON::Parser parser;
			Poco::Dynamic::Var result = parser.parse(json);
			Poco::JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
			Poco::DynamicStruct ds = *object;

			std::string dobDate = ds["dateOfBirth"]["date"];
			std::string dobMonth = ds["dateOfBirth"]["month"];
			std::string dobYear = ds["dateOfBirth"]["year"];
			std::string cityName = ds["location"]["city"];
			std::string postalCode = ds["location"]["postCode"];
			std::string additionalInfo = ds["location"]["state"];
			std::string streetName = ds["location"]["street"];
			std::string firstName = ds["name"]["firstName"];
			std::string secondName = ds["name"]["lastName"];

			str<<"quit";


			int dob_Date= atoi(dobDate.c_str());
			if(0 == dob_Date) {
				throw 90;
			}
			int dob_Month=atoi(dobMonth.c_str());
			if(0 == dob_Month) {
				throw 91;
			}
			int dob_Year=atoi(dobYear.c_str());
			if(0==dob_Year) {
				throw 92;
			}
			unsigned short postal_Code=atoi(postalCode.c_str());
			if(0==postal_Code){
				throw 93;
			}
			Poco::Data::Date dateOfBirth;
			dateOfBirth.assign(dob_Year, dob_Month, dob_Date);

			Student details{firstName, secondName, dateOfBirth,streetName, cityName, postal_Code, additionalInfo};
			students.insert(std::make_pair(details.getMatrikelNumber(), details));
		}
		catch (int errorCode) {
			std::cout << "Exception: Handled. Invalid Data obtained" << std::endl;
		}
		catch(...) {
			std::cout << "Other invalid data" << std::endl;
		}

		socket.shutdownSend();
		socket.close();

	}
}

