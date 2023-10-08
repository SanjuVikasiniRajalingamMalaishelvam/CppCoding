/*
 * Project.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef PROJECT_H_
#define PROJECT_H_

#include <iostream>
#include <string>
#include "Poco/Data/Date.h"
#include "Poco/JSON/Object.h"
#include "Poco/JSON/Array.h"
#include <vector>

#include "Assignee.h"
class Project
{
protected:
	Project(Poco::JSON::Object::Ptr data);
private:
	std::string name;
	int numberOfEmployees;
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	std::vector<Assignee> assignees;


public:
	Project(std::string name, int count, Poco::Data::Date startDate, Poco::Data::Date endDate);
	virtual ~Project();
	void addAssignee(Assignee *ptr);
	Poco::JSON::Object::Ptr to_json()const;
	static Project* from_json(Poco::JSON::Object::Ptr data);
	std::string getName()const;

};

#endif /* PROJECT_H_ */
