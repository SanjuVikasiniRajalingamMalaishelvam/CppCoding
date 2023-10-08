/*
 * Transaction.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <iostream>
#include <string>

#include "Poco/Data/Date.h"
typedef enum
{
	credit,
	debit,
	none
}transactionType_t;
class Transaction
{
private:
	unsigned int amountTransferred;
	int toAccount;
	Poco::Data::Date date;
	transactionType_t type;

public:
	Transaction(unsigned int amountTransferred, int toAccount);
	virtual ~Transaction();
	unsigned int getAmountTransferred()const;
	int getToAccount()const;
	void print();
};

#endif /* TRANSACTION_H_ */
