/*
 * Customer.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Customer.h"

using namespace std;
Customer::Customer(std::string firstName, std::string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

Customer::~Customer()
{
	// TODO Auto-generated destructor stub
}

std::string Customer::getFirstName() const
{
	return this->firstName;
}

std::string Customer::getLastName() const
{
	return this->lastName;
}

std::string Customer::getFullName() const
{
	return this->firstName+this->lastName;
}
