/*
 * Bank.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "Account.h"
#include "Customer.h"

class Bank
{
private:
	std::map<std::string, std::vector<Account>> customers;
	unsigned int maxAccounts;
	unsigned int maxTransactions;

public:
	Bank(unsigned int maxAccounts, unsigned int maxTransactions);
	virtual ~Bank();
	bool addUserAccount(std::string user, unsigned int balance);
	bool deleteUserAccount(std::string name, int accountID);
	bool deleteUserAccount(std::string name);
	bool trasnferMoney(int acc1, int acc2, int amount);
	void print();
	const std::map<std::string, std::vector<Account>>& getCustomers ()const;
};

#endif /* BANK_H_ */
