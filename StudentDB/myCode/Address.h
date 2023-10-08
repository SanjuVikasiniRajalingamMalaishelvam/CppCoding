/*
 * Address.h
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_


//Standard header file
#include <string>

/**
 * Class Address is of composition to the student
 * Gets all the address details of the students in Db and returns
 */
class Address
{
private:
	std::string street;
	unsigned short postalCode;
	std::string cityName;
	std::string additionalInfo;

public:
	Address();
	Address(std::string street, std::string cityName, unsigned short postalCode, std::string additionalInfo);

	/**
	 * Method to get street name
	 */
	std::string getStreet();

	/**
	 * Method to get postal code
	 */
	unsigned short getPostalCode();

	/**
	 * Method to get the city name
	 */
	std::string getCityName();

	/**
	 * Method to get additional info on address
	 */
	std::string getAdditionalInfo();

	virtual ~Address();
};

#endif /* ADDRESS_H_ */
