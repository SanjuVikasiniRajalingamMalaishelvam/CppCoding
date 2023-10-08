/*
 * Developer.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Developer.h"

using namespace std;
Developer::Developer(std::string name, int employeeID, std::string email,
		Poco::Data::Date dob, int salary, int hours): Employee(name, employeeID, email, dob, salary)
{
	this->hours = hours;
}

Developer::~Developer()
{
	// TODO Auto-generated destructor stub
}

Developer::Developer(Poco::JSON::Object::Ptr data):Employee(data)
{
	this->hours = data->get("hours").convert<int>();
}

Poco::JSON::Object::Ptr Developer::to_json()
{
	Poco::JSON::Object::Ptr objPtr = Employee::to_json();
	objPtr->set("hours", this->hours);

	return objPtr;
}

Developer::Developer(const Developer &obj)
{
	this->hours = 0;
}

Developer& Developer::operator =(const Developer &obj)
{
	this->hours = obj.hours;
	return *this;
}

Developer* Developer::from_json(Poco::JSON::Object::Ptr data)
{

	Developer *developer = nullptr;
	if (data->isNull("teamMembersCount"))
	{
		developer = new Developer(data);
	}
	return developer;
}
