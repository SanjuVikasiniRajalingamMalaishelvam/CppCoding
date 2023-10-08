/*
 * Novel.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef NOVEL_H_
#define NOVEL_H_

#include "Book.h"

class Novel: public Book
{
private:
	std::string storyType;
public:
	Novel(std::string name, std::string author, std::string storyType);
	virtual ~Novel();
	std::string toString()const;
	void write(std::ostream& out);
	static Novel* toType(Book *book);
};

#endif /* NOVEL_H_ */
