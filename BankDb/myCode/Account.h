/*
 * Account.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>

#include "Transaction.h"
class Account
{
private:
    int id;
	int remainingBalance;
	static int accountIDValue;
	std::vector<Transaction> transaction;

public:
	Account(unsigned int remainingBalance = 50);
	virtual ~Account();
	int updateAccount();
	unsigned int getRemainingBalance()const;
	bool operator+(int amount);
	bool operator-(int amount);
	const std::vector<Transaction>& getTransactions()const;
	void storeTransactions(const Transaction& transaction);
	void print();
	int getAccountId()const;
};

#endif /* ACCOUNT_H_ */
