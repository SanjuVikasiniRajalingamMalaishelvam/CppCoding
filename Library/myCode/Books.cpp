/*
 * Books.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Books.h"

using namespace std;
Books::Books()
{
	// TODO Auto-generated constructor stub

}

Books::~Books()
{
	// TODO Auto-generated destructor stub
}

void Books::addBook(std::string genre, Book *ptrBook)
{
	cout << "Inside add books";
	auto itr = books.find(genre);
	if (itr!= books.end())
	{
		itr->second.push_back(ptrBook);
	}
	else
	{
		cout << "Am here"<<endl;
		list<Book*> booksList;
		booksList.push_back(ptrBook);
		books[genre] = booksList;
		cout << "Amhere"<<endl;
		books.insert(make_pair(genre, booksList));
	}
}

void Books::printBooks()
{
	for (auto itrBooks = books.begin(); itrBooks!= books.end(); itrBooks++)
	{
		cout << itrBooks->first << ":";
		for (auto itr = itrBooks->second.begin(); itr!= itrBooks->second.end(); itr++)
		{
			cout << (**itr) <<endl;
		}
	}
}

std::map<std::string, std::list<Book*>> Books::getBooks()
{
	return this->books;
}

void Books::write(std::ostream &out)
{
	for (auto itr = books.begin(); itr!= books.end(); itr++)
	{
		out << itr->first << ";";
		for (auto itr2 = itr->second.begin(); itr2!= itr->second.end(); itr2++)
		{
			(*itr2)->write(out);
		}

	}
}
