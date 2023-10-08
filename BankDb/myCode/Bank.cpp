/*
 * Bank.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Bank.h"
using namespace std;
Bank::Bank(unsigned int maxAccounts, unsigned int maxTransactions)
{
	this->maxAccounts = maxAccounts;
	this->maxTransactions = maxTransactions;
}

Bank::~Bank()
{
	// TODO Auto-generated destructor stub
}

bool Bank::addUserAccount(std::string user, unsigned int balance)
{
	if(maxAccounts >0)
	{
		this->customers[user].push_back(Account(balance));
		maxAccounts--;
		return true;
	}
	else
	{
		return false;
	}
}

bool Bank::deleteUserAccount(std::string name, int accountID)
{
	auto itr = customers.find(name);
	if (itr!= customers.end())
	{
		for (auto itrVec = itr->second.begin(); itrVec!= itr->second.end(); itrVec++)
		{
			if (itrVec->getAccountId() == accountID)
			{
				itr->second.erase(itrVec);
				return true;
			}
		}
	}
	return false;
}

bool Bank::deleteUserAccount(std::string name)
{
	this->customers.erase(name);
	return true;
}

bool Bank::trasnferMoney(int acc1, int acc2, int amount)
{

}

void Bank::print()
{
}

const std::map<std::string, std::vector<Account> >& Bank::getCustomers() const
{
	return this->customers;
}
