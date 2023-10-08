/*
 * FirmaDB.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef FIRMADB_H_
#define FIRMADB_H_

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <list>
#include "Poco/JSON/Parser.h"
#include "Poco/DynamicStruct.h"


#include "Employee.h"
#include "Project.h"
#include "Developer.h"
#include "Manager.h"

class FirmaDB
{
private:
	std::map<int, std::unique_ptr<Employee>> employees;
	std::list<std::shared_ptr<const Project>> projects;
public:
	FirmaDB();
	virtual ~FirmaDB();
	void addProject(Project *project);
	void addEmployee(Employee& employee);
	void assignEmployeeToProject(std::string projectName, int employeeID, int allotedHours);
	Poco::JSON::Object::Ptr to_json()const;
	void print();
	void write(std::ostream& out)const;
	void updateEmployee(int employeeID, Operation_e updateCondition);
	void read(std::istream& in);
};

#endif /* FIRMADB_H_ */
