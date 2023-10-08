/*
 * CDay1.h
 *
 *  Created on: 5 Dec 2022
 *      Author: sanju
 */

#ifndef CDAY1_H_
#define CDAY1_H_


#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <map>


class CDay1
{
private:
	int elveCount = 1;
	int CalorieCount_1 = 0;
	std::map<int, int>calorieCountMap;
public:
	CDay1();
	~CDay1();

	void readData(std::istream& in);
	void calculateCalories();
};

#endif /* CDAY1_H_ */
