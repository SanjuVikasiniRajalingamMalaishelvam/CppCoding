/*
 * TextConvert.h
 *
 *  Created on: 13 Feb 2023
 *      Author: sanju
 */

#ifndef TEXTCONVERT_H_
#define TEXTCONVERT_H_

#include <iostream>
#include <string>
#include "Poco/TextConverter.h"
#include "Poco/TextEncoding.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/Windows1252Encoding.h"
#include "Poco/DateTime.h"

class TextConvert
{
private:
	std::string text;
public:
	TextConvert(std::string text);
	virtual ~TextConvert();
	void run();
};

#endif /* TEXTCONVERT_H_ */
