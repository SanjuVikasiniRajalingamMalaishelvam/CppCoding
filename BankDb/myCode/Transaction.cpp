/*
 * Transaction.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "Transaction.h"

using namespace std;
Transaction::Transaction(unsigned int amountTransferred, int toAccount)
{
	this->amountTransferred = amountTransferred;
	this->toAccount = toAccount;
	this->date.assign(1, 1, 1);
	this->type = none;
}

Transaction::~Transaction()
{
	// TODO Auto-generated destructor stub
}

unsigned int Transaction::getAmountTransferred() const
{
	return this->amountTransferred;
}

int Transaction::getToAccount() const
{
	return this->toAccount;
}

void Transaction::print()
{
	cout << to_string(this->amountTransferred) << " transferred to the account " << to_string(toAccount) << " on " << date.day() << "." << date.month() << ":" << date.year() <<endl;
}
