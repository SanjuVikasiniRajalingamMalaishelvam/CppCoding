/*
 * TextBook.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef TEXTBOOK_H_
#define TEXTBOOK_H_

#include "Book.h"
class TextBook: public Book
{
private:
	std::string subject;
public:
	TextBook(std::string name, std::string author, std::string subject);
	virtual ~TextBook();
	std::string toString()const;
	void write(std::ostream& out);
	static TextBook* toType(Book *book);
};

#endif /* TEXTBOOK_H_ */
