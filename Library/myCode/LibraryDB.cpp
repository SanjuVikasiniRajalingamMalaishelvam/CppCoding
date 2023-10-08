/*
 * LibraryDB.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "LibraryDB.h"

using namespace std;
LibraryDB::LibraryDB(Books &booksPtr)
{
	this->books = &booksPtr;
}

LibraryDB::~LibraryDB()
{
	// TODO Auto-generated destructor stub
}

Book* LibraryDB::searchBook(std::string genre, std::string name, std::string author)
{
	Book* bookPtr = nullptr;
	std::map<std::string, std::list<Book*> > booksMap= books->getBooks();
	for (auto itr = booksMap.begin(); itr!= booksMap.end(); itr++)
	{
		if (itr->first == genre)
		{
			for (auto itrlist = itr->second.begin(); itrlist != itr->second.end(); itrlist++)
			{
				if (((*itrlist)->getName() == name) && ((*itrlist)->getAuthor() == author))
				{
					bookPtr = (*itrlist);
				}
			}
		}
	}
	return bookPtr;
}
void LibraryDB::assignBook(int userID, std::string genre, std::string name,
		std::string author)
{
	for (auto itrUser = users.begin(); itrUser!= users.end(); itrUser++)
	{

		if ((*itrUser)->getId() == userID)
		{
			Book *bookPtr = searchBook(genre, name, author);

			if (nullptr!= bookPtr)
			{
				booksAssigned[userID].push_back(bookPtr);
			}
		}
	}
}

void LibraryDB::addUser(User *userPtr)
{
	users.push_back(userPtr);
}

void LibraryDB::addBook(std::string genre, Book *bookPtr)
{
	books->addBook(genre, bookPtr);
}

void LibraryDB::print()
{
	cout << booksAssigned.size() <<endl;
	for (auto itr = booksAssigned.begin(); itr!= booksAssigned.end(); itr++)
	{
		cout << itr->first << ";";
		for (auto itrBooks = itr->second.begin(); itrBooks!= itr->second.end(); itrBooks++)
		{
			cout << (**itrBooks) <<endl;
		}
	}
}

void LibraryDB::write(std::ostream &out)
{
	out << "{";
	for (auto itr = users.begin(); itr!= users.end(); itr++)
	{
		(*itr)->write(out);
	}
	out << "}" <<endl;

	for (auto itr = booksAssigned.begin(); itr!= booksAssigned.end(); itr++)
	{
		out << itr->first << ";";
		for (auto itrBooks = itr->second.begin(); itrBooks!= itr->second.end(); itrBooks++)
		{
			(*itrBooks)->write(out);
		}
	}

}

void LibraryDB::read(std::istream &in)
{
	string line = "";

}
