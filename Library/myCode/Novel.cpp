/*
 * Novel.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Novel.h"

using namespace std;
Novel::Novel(std::string name, std::string author, std::string storyType): Book(name, author)
{
	this->storyType = storyType;
}

Novel::~Novel()
{
	// TODO Auto-generated destructor stub
}

std::string Novel::toString() const
{
	string str ="";
	str = Book::toString() + this->storyType;
	return str;
}

void Novel::write(std::ostream &out)
{
	out << "N" << ";";
	Book::write(out);
	out << this->storyType <<endl;
}

Novel* Novel::toType(Book *book)
{
	Novel *novelPtr = nullptr;
	novelPtr = dynamic_cast<Novel*>(book);

	return novelPtr;
}
