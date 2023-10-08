/*
 * User.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "User.h"

int User::nextID = 1;
using namespace std;
User::User(int id, std::string name, std::string address)
{
	this->ID = id;
	this->name = name;
	this->address = address;

}

User::~User()
{
	// TODO Auto-generated destructor stub
}

int User::getNextID()
{
	return User::nextID++;
}

int User::getId()
{
	return this->ID;
}

std::string User::toString()
{
	string str = "";
	str = to_string(this->ID) + ";" +this->name + ";" + this->address;

	return str;
}

void User::write(std::ostream &out)
{
	out << "{" << toString() << "}" <<endl;
}
