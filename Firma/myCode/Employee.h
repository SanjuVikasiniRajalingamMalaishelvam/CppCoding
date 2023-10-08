/*
 * Employee.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include "Poco/Data/Date.h"
#include "Poco/JSON/Object.h"
typedef enum
{
	Increment,
	Promote,
	Delete

}Operation_e;

class Employee
{
protected:
	Employee(Poco::JSON::Object::Ptr data);
private:
	std::string name;
	int employeeID;
	std::string email;
	Poco::Data::Date dob;
	int salary;
	static int nextID;
public:
	Employee();
	Employee(std::string name, int employeeID, std::string email, Poco::Data::Date dob, int salary);
	Employee(const Employee& obj);
	Employee& operator=(const Employee& obj);
	virtual ~Employee();
	static int getNextId();
	virtual Poco::JSON::Object::Ptr to_json();
	std::string to_String();
	friend std::ostream& operator<<(std::ostream& lhs, Employee& rhs);
	int getEmployeeID()const;
};

#endif /* EMPLOYEE_H_ */
