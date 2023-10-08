/*
 * Address.cpp
 *
 *  Created on: 13 Jan 2022
 *      Author: sanju
 */


//Project's header file
#include "Address.h"

//Standard header file
#include <iostream>

/**
 *Default constructor of Address and initialization of attributes
 */
Address::Address()
{
	street="0";
	cityName="0";
	postalCode =0;
	additionalInfo="0";

}

/**
 * Parametrized constructor of Address that has the address details
 */
Address::Address(std::string street, std::string cityName, unsigned short postalCode, std::string additionalInfo)
{
	this->street=street;
	this->cityName=cityName;
	this->postalCode=postalCode;
	this->additionalInfo=additionalInfo;

}

Address::~Address()
{

}


/**
 * Method to get street name
 */
std::string Address::getStreet()
{
	return street;
}

/**
 * Method to get postal code
 */
unsigned short Address::getPostalCode()
{
	return postalCode;
}

/**
 * Method to get city name
 */
std::string Address::getCityName()
{
	return cityName;
}

/**
 * Method to get additional info about address
 */
std::string Address::getAdditionalInfo()
{
	return additionalInfo;
}
