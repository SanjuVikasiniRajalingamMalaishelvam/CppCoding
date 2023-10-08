/*
 * Books.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef BOOKS_H_
#define BOOKS_H_

#include "Book.h"
#include <map>
#include <list>
class Books
{
private:
	std::map<std::string, std::list<Book*>> books;
public:
	Books();
	virtual ~Books();
	void addBook(std::string genre, Book* ptrBook);
	void printBooks();
	std::map<std::string, std::list<Book*>> getBooks();
	void write(std::ostream& out);
};

#endif /* BOOKS_H_ */
