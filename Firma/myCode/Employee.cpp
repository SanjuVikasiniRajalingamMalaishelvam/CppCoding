/*
 * Employee.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Employee.h"

int Employee::nextID = 1;

using namespace std;
Employee::Employee(std::string name, int employeeID, std::string email,
		Poco::Data::Date dob, int salary)
{
	this->name = name;
	this->employeeID = this->nextID;
	nextID++;
	this->email = email;
	this->salary =salary;
	this->dob = dob;
}

Employee::~Employee()
{
	// TODO Auto-generated destructor stub
}

int Employee::getNextId()
{
	return Employee::nextID;
}

std::string Employee::to_String() {
//	string str ="";
//
//	Poco::JSON::Object::Ptr ptr = to_json();
//	Poco::DynamicStruct ds = *ptr;
//	ds.toString();

	stringstream inputString;
	to_json()->stringify(inputString, 4);

	return inputString.str();
}

Employee::Employee(const Employee &obj)
{
	this->name = obj.name;
	this->employeeID = obj.nextID;
	obj.nextID++;
	this->email = obj.email;
	this->salary = obj.salary;
	this->dob = obj.dob;
}

Employee& Employee::operator =(const Employee &obj)
{
	this->name = obj.name;
	this->employeeID = obj.nextID;
	obj.nextID++;
	this->email = obj.email;
	this->salary = obj.salary;
	this->dob = obj.dob;

	return *this;
}

int Employee::getEmployeeID() const
{
	return this->employeeID;
}
std::ostream& operator<<(std::ostream& lhs, Employee& rhs)
{
	lhs << rhs.to_String();
	return lhs;
}

Poco::JSON::Object::Ptr Employee::to_json()
{
	Poco::JSON::Object::Ptr objPtr = new Poco::JSON::Object(Poco::JSON_PRESERVE_KEY_ORDER);
	objPtr->set("name", this->name);
	objPtr->set("employeeID", this->employeeID);
	objPtr->set("email", this->email);
	objPtr->set("dob", to_string(this->dob.day())+":"+to_string(this->dob.month())+":"+to_string(this->dob.year()));
	objPtr->set("salary", this->salary);


	return objPtr;
}

Employee::Employee(Poco::JSON::Object::Ptr data)
{
	this->name = data->get("name").convert<string>();
	this->employeeID = data->get("employeeID").convert<int>();
	this->email = data->get("email").convert<string>();
	this->salary = data->get("salary").convert<int>();

	int a =1;
	Poco::DateTime dt = Poco::DateTimeParser::parse("%D:%M:%Y", data->get("dob").toString(), a);
	Poco::Data::Date dob;
	dob.assign(dt.year(), dt.month(), dt.day());
	this->dob = dob;
}

Employee::Employee()
{
}
