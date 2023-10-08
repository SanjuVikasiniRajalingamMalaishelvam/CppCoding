/*
 * Developer.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef DEVELOPER_H_
#define DEVELOPER_H_

#include <iostream>
#include <string>
#include "Employee.h"


class Developer: public Employee
{
protected:
	Developer(Poco::JSON::Object::Ptr data);
private:
	int hours;
public:
	Developer(std::string name, int employeeID, std::string email, Poco::Data::Date dob, int salary, int hours);
	Developer(const Developer& obj);
	Developer& operator=(const Developer& obj);
	virtual ~Developer();
	Poco::JSON::Object::Ptr to_json();
	static Developer* from_json(Poco::JSON::Object::Ptr data);
};

#endif /* DEVELOPER_H_ */
