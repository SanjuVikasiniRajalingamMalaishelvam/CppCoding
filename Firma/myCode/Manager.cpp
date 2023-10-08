/*
 * Manager.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Manager.h"

using namespace std;
Manager::Manager(std::string name, int employeeID, std::string email,
		Poco::Data::Date dob, int salary, int hours, int teamMembersCount):Employee(name, employeeID, email, dob, salary)
{
	this->hours = hours;
	this->teamMembersCount = teamMembersCount;
}

Manager::~Manager()
{
	// TODO Auto-generated destructor stub
}

Manager::Manager(Poco::JSON::Object::Ptr data):Employee(data)
{
	this->hours = data->get("hours").convert<int>();
	this->teamMembersCount =data->get("teamMembersCount").convert<int>();
}

Poco::JSON::Object::Ptr Manager::to_json()
{
	Poco::JSON::Object::Ptr objPtr=Employee::to_json();
	objPtr->set("hours", this->hours);
	objPtr->set("teamMembersCount", this->teamMembersCount);


	return objPtr;
}

Manager* Manager::from_json(Poco::JSON::Object::Ptr data)
{
	Manager *manager = nullptr;
	if (!data->isNull("teamMembersCount"))
	{
		manager = new Manager(data);
	}
	return manager;
}
