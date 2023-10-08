/*
 * Assignee.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef ASSIGNEE_H_
#define ASSIGNEE_H_

#include <iostream>
#include <string>
#include "Employee.h"
class Assignee
{
private:
	Employee *employee;
	int allotedHours;
public:
	Assignee(Employee *employee, int allotedHours);
	virtual ~Assignee();
	Poco::JSON::Object::Ptr to_json()const;
	Employee* getEmployee()const;
};

#endif /* ASSIGNEE_H_ */
