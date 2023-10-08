/*
 * Customer.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include <string>
class Customer
{
private:
	std::string firstName;
	std::string lastName;
public:
	Customer(std::string firstName, std::string lastName);
	virtual ~Customer();
	std::string getFirstName()const;
	std::string getLastName()const;
	std::string getFullName()const;
};

#endif /* CUSTOMER_H_ */
