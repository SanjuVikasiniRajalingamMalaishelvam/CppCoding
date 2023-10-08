/*
 * Project.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Project.h"

using namespace std;
Project::Project(std::string name, int count, Poco::Data::Date startDate,
		Poco::Data::Date endDate)
{
	this->name = name;
	this->numberOfEmployees = count;
	this->startDate = startDate;
	this->endDate = endDate;

	if (endDate.operator <(startDate))
	{
		throw std::invalid_argument("End data prior to startDate");
	}
}

Project::~Project()
{
	// TODO Auto-generated destructor stub
}

void Project::addAssignee(Assignee *ptr)
{
	bool RC = false;
	if ((int)assignees.size() <= this->numberOfEmployees)
	{
		for (auto itr = assignees.begin(); itr!= assignees.end(); itr++)
		{
			if (itr->getEmployee()->getEmployeeID() == ptr->getEmployee()->getEmployeeID())
			{
				RC = true;
			}
		}
	}
	if (false == RC)
	{
		assignees.push_back(*ptr);
	}


}

Poco::JSON::Object::Ptr Project::to_json()const
{
	Poco::JSON::Object::Ptr objPtr = new Poco::JSON::Object;
	Poco::JSON::Array::Ptr arrayPtr = new Poco::JSON::Array;

	objPtr->set("name", this->name);
	objPtr->set("numberOfEmployees", this->numberOfEmployees);
	objPtr->set("startDate", to_string(this->startDate.day())+":"+to_string(this->startDate.month())+":"+to_string(this->startDate.year()));
	objPtr->set("endDate", to_string(this->endDate.day())+":"+to_string(this->endDate.month())+":"+to_string(this->endDate.year()));

	for (auto itr = assignees.begin(); itr!= assignees.end(); itr++)
	{
		arrayPtr->add(itr->to_json());
	}
	objPtr->set("assignees", *arrayPtr);
	return objPtr;
}

Project* Project::from_json(Poco::JSON::Object::Ptr data)
{
	Project *project = new Project(data);

	return project;
}

std::string Project::getName() const
{
	return this->name;
}

Project::Project(Poco::JSON::Object::Ptr data)
{
	this->name = data->get("name").convert<string>();
	this->numberOfEmployees = data->get("numberOfEmployees").convert<int>();
	this->startDate = data->get("startDate");
	this->endDate =  data->get("endDate");
}
