/*
 * User.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>

class User
{
private:
	static int nextID;
	int ID;
	std::string name;
	std::string address;

public:
	User(int id, std::string name, std::string address);
	virtual ~User();
	static int getNextID();
	int getId();
	friend std::ostream& operator<<(std::ostream& lhs, User& rhs);
	std::string toString();
	void write(std::ostream& out);

};

#endif /* USER_H_ */
