/*
 * Account.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Account.h"

using namespace std;
int Account::accountIDValue = 10000;
Account::Account(unsigned int remainingBalance)
{
	this->remainingBalance = remainingBalance;
	this->id = updateAccount();
}

Account::~Account()
{
	// TODO Auto-generated destructor stub
}

int Account::updateAccount()
{
	this->id = accountIDValue;
	accountIDValue++;
	return this->id;
}

unsigned int Account::getRemainingBalance() const
{
	return this->remainingBalance;
}

bool Account::operator +(int amount)
{
	if (amount + remainingBalance >0)
	{
		this->remainingBalance = this->remainingBalance + amount;
		return true;
	}
	return false;
}

bool Account::operator -(int amount)
{
	if (remainingBalance - amount >0)
	{
		this->remainingBalance = this->remainingBalance - amount;
		return true;
	}
	return false;
}

const std::vector<Transaction>& Account::getTransactions() const
{
	return this->transaction;
}

void Account::storeTransactions(const Transaction &transaction)
{
	this->transaction.push_back(transaction);
}

void Account::print()
{
	cout << "Accound ID " << this->id << "  :";
	for (auto itr = transaction.begin(); itr!= transaction.end(); itr++)
	{
		itr->print();
	}
}

int Account::getAccountId() const
{
	return this->id;
}
