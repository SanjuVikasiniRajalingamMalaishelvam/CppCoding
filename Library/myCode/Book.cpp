/*
 * Book.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Book.h"

using namespace std;
Book::Book(std::string name, std::string author)
{
	this->name = name;
	this->author = author;
}

const std::string& Book::getAuthor() const
{
	return author;
}


const std::string& Book::getName() const
{
	return name;
}

Book::~Book()
{
	// TODO Auto-generated destructor stub
}

std::string Book::toString() const
{
	string str = "";
	str = this->name + ";" + this->author + ";";

	return str;
}

void Book::write(std::ostream &out)
{
	out << this->name << ";" << this->author << ";";
}
std::ostream& operator<<(std::ostream& lhs, Book& rhs)
{
	lhs << rhs.toString();
	return lhs;
}
