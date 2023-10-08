/*
 * LibraryDB.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef LIBRARYDB_H_
#define LIBRARYDB_H_

#include "User.h"
#include "Books.h"
#include <vector>


class LibraryDB
{
private:
	std::vector<User*> users;
	std::map<int, std::list<Book*>> booksAssigned;
	Books *books;
public:
	LibraryDB(Books &booksPtr);
	virtual ~LibraryDB();
	Book* searchBook(std::string genre, std::string name, std::string author);
	void assignBook(int userID, std::string genre, std::string name, std::string author);
	void addUser(User* userPtr);
	void addBook(std::string genre, Book *bookPtr);
	void print();
	void write(std::ostream& out);
	void read(std::istream& in);
};

#endif /* LIBRARYDB_H_ */
