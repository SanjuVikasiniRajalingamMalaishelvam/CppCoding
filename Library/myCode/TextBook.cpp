/*
 * TextBook.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "TextBook.h"

using namespace std;

TextBook::TextBook(std::string name, std::string author, std::string subject):Book(name, author)
{
	this->subject = subject;
}

TextBook::~TextBook()
{
	// TODO Auto-generated destructor stub
}

std::string TextBook::toString() const
{
	string str ="";
	str = Book::toString() + this->subject;
	return str;
}

void TextBook::write(std::ostream &out)
{
	out << "T" << ";";
	Book::write(out);
	out << this->subject <<endl;
}

TextBook* TextBook::toType(Book *book)
{
	TextBook *textPtr = nullptr;
	textPtr = dynamic_cast<TextBook*>(book);

	return textPtr;
}
