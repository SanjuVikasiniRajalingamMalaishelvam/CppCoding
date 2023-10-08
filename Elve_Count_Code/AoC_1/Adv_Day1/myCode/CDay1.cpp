/*
 * CDay1.cpp
 *
 *  Created on: 5 Dec 2022
 *      Author: sanju
 */

#include "CDay1.h"
using namespace std;

CDay1::CDay1()
{


}

CDay1::~CDay1()
{
	// TODO Auto-generated destructor stub
}

void CDay1::readData(std::istream &in)
{
	std::string line ="";
	std::string temp;


	for (line; getline(in, line); )
	{
		std::stringstream inputString(line);
		if (!line.empty())
		{
			std::getline(inputString, temp,' ');
			int tempInt = stoi(temp);
			CalorieCount_1 = CalorieCount_1+tempInt;

		}
		else
		{
			calorieCountMap.insert(std::pair<int,int>(elveCount, CalorieCount_1));

			elveCount++;
			CalorieCount_1 = 0;
		}
	}
}


void CDay1::calculateCalories()
{
	int maxValCalories = 0;
	int elveNumber = 0;
	for (auto itrNew = calorieCountMap.begin(); itrNew!= calorieCountMap.end(); itrNew++)
	{
//		cout <<"Elve number: " << itrNew->first << "\t";
//		cout <<"Calories: " << itrNew->second <<endl;

		if (itrNew->second > maxValCalories)
		{
			maxValCalories = itrNew->second;
			elveNumber = itrNew->first;
		}

	}

	cout << "The elve with the maximum calories is: " <<endl;
	cout << "Elve number: "<< elveNumber << "  with the calories of: " << maxValCalories <<endl;
}
