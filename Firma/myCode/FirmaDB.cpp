/*
 * FirmaDB.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "FirmaDB.h"
using namespace std;
FirmaDB::FirmaDB()
{
	// TODO Auto-generated constructor stub

}

FirmaDB::~FirmaDB()
{
	// TODO Auto-generated destructor stub
}

void FirmaDB::addProject(Project *project)
{
	projects.push_back(std::shared_ptr<Project>(project));
}

void FirmaDB::addEmployee(Employee &employee)
{
	employees.insert(make_pair(employee.getEmployeeID(), std::unique_ptr<Employee>(&employee)));
}

void FirmaDB::assignEmployeeToProject(std::string projectName, int employeeID, int allotedHours)
{

	auto itr = employees.find(employeeID);
	if(itr!= employees.end())
	{
		Assignee *newAssignee = new Assignee(itr->second.get(), allotedHours);
		for (auto itr = projects.begin(); itr!= projects.end(); itr++)
		{
			if (itr->get()->getName() == projectName)
			{
				const_cast<Project*>(itr->get())->addAssignee(newAssignee);
			}
		}
	}

}

Poco::JSON::Object::Ptr FirmaDB::to_json()const
{
	Poco::JSON::Object::Ptr objPtr = new Poco::JSON::Object;
	Poco::JSON::Array::Ptr arrayPtr = new Poco::JSON::Array;
	for (auto itrProjects = projects.begin(); itrProjects!= projects.end(); itrProjects++)
	{
		arrayPtr->add((itrProjects->get()->to_json()));
	}
	objPtr->set("Projects",*arrayPtr);
	arrayPtr->clear();

	for (auto itrEmployees = employees.begin(); itrEmployees!= employees.end(); itrEmployees++)
	{
		arrayPtr->add((itrEmployees->second.get()->to_json()));
	}
	objPtr->set("employees", *arrayPtr);

	return objPtr;
}

void FirmaDB::print()
{
	Poco::JSON::Object::Ptr objPtr = to_json();
	objPtr->stringify(cout, 4);
}

void FirmaDB::write(std::ostream &out)const
{
	Poco::JSON::Object::Ptr objPtr = to_json();
	objPtr->stringify(out, 4);
}

void FirmaDB::updateEmployee(int employeeID, Operation_e updateCondition)
{
}

void FirmaDB::read(std::istream &in)
{

//	employees.clear();
//	projects.clear();

	cout <<"In read"<<endl;
	string line ="";
	stringstream inputString;
	inputString<< in.rdbuf();

	line = inputString.str();
cout << "Line:  " <<line <<endl;
	Poco::JSON::Parser parser;
	Poco::Dynamic::Var result = parser.parse(line);
	Poco::JSON::Object::Ptr objPtr = result.extract<Poco::JSON::Object::Ptr>();
	Poco::DynamicStruct ds = *objPtr;

	if (ds["Projects"].isArray())
	{
		for (int idx =0; idx < (int)(ds["Projects"].size()); idx++)
		{

			string name = ds["Projects"][idx]["name"];
			int numberofEmployees = ds["Projects"][idx]["numberOfEmployees"].convert<int>();
			string startDate = ds["Projects"][idx]["startDate"];
			string endDate = ds["Projects"][idx]["endDate"];


			int a =1;
			Poco::DateTime dt = Poco::DateTimeParser::parse("%D:%M:%Y", startDate, a);
			Poco::Data::Date start;
			start.assign(dt.year(), dt.month(), dt.day());

			Poco::DateTime dt1 = Poco::DateTimeParser::parse("%D:%M:%Y", endDate, a);
			Poco::Data::Date end;
			end.assign(dt1.year(), dt1.month(), dt1.day());


			if (ds["Projects"][idx]["assignees"].isArray())
			{

				for (int idx2 = 0; idx2 < (int)ds["Projects"][idx]["assignees"].size(); idx2++)
				{
					int emplyeeID = ds["Projects"][idx]["assignees"][idx2]["EmployeeID"].convert<int>();
					int hoursAlloted = ds["Projects"][idx]["assignees"][idx2]["allotedHours"].convert<int>();

				}
			}
//			cout << name << "  "<< startDate << "  " <<endDate <<endl;
		}
	}
	if(ds["employees"].isArray())
	{
		for (int idx =0; idx < (int)(ds["employees"].size()); idx++)
		{
			Poco::JSON::Object::Ptr obj = objPtr->getArray("employees").get()->getObject(idx);

			Developer *devPtr = Developer::from_json(obj);
			Manager *manPtr = Manager::from_json(obj);


			if (nullptr!= devPtr)
			{
				cout << devPtr->to_String() <<endl;
			}
			else if (nullptr!= manPtr)
			{

				cout << manPtr->to_String()<<endl;
			}

		}
	}

	cout << "CRASH" <<endl;

}
