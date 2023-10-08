/*
 * TextConvert.cpp
 *
 *  Created on: 13 Feb 2023
 *      Author: sanju
 */

#include "TextConvert.h"
using namespace std;

TextConvert::TextConvert(std::string text)
{
	this->text = text;

}

TextConvert::~TextConvert()
{
	// TODO Auto-generated destructor stub
}

void TextConvert::run()
{
	cout << this->text.size() <<endl;
	Poco::UTF8Encoding utf8enc;
	Poco::Windows1252Encoding winEnco;
	Poco::TextConverter conv(utf8enc, winEnco);
	std::string converted;
	conv.convert(this->text, converted);
	cout << converted <<endl;


	cout << "-------------------" <<endl;
	Poco::DateTime dt(Poco::Timestamp::fromEpochTime(1000000000));
	cout << dt.year() <<endl;
	cout << dt.month() <<endl;
	cout << dt.day() <<endl;
	cout << dt.hour() << endl;
	cout << dt.minute() <<endl;
	cout << dt.second() <<endl;




}
