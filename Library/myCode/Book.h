/*
 * Book.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <string>

class Book
{
private:
	std::string name;
	std::string author;
public:
	Book(std::string name, std::string author);
	virtual ~Book();
	const std::string& getAuthor() const;
	const std::string& getName() const;
	virtual std::string toString()const;
	friend std::ostream& operator<<(std::ostream& lhs, Book& rhs);
	virtual void write(std::ostream& out);
};

#endif /* BOOK_H_ */
