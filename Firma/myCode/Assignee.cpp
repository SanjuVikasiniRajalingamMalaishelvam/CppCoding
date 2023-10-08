/*
 * Assignee.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Assignee.h"

using namespace std;
Assignee::Assignee(Employee *employee,  int allotedHours)
{
	this->employee = employee;
	this->allotedHours = allotedHours;
}

Assignee::~Assignee()
{
	// TODO Auto-generated destructor stub
}

Poco::JSON::Object::Ptr Assignee::to_json()const
{
	Poco::JSON::Object::Ptr objPtr = new Poco::JSON::Object;

	objPtr->set("EmployeeID", employee->getEmployeeID());
	objPtr->set("allotedHours", this->allotedHours);

	return objPtr;
}

Employee* Assignee::getEmployee()const
{
	return employee;
}
