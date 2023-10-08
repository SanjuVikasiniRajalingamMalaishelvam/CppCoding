/*
 * Manager.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include <iostream>
#include <string>
#include "Employee.h"

class Manager: public Employee
{
protected:
	Manager(Poco::JSON::Object::Ptr data);
private:
	int hours;
	int teamMembersCount;
public:
	Manager(std::string name, int employeeID, std::string email, Poco::Data::Date dob, int salary, int hours, int teamMembersCount);
	virtual ~Manager();
	Poco::JSON::Object::Ptr to_json();
	static Manager* from_json(Poco::JSON::Object::Ptr data);
};

#endif /* MANAGER_H_ */
