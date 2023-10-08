/*
 * GridPosition.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <iostream>
#include <string>

class GridPosition
{
private:
	char row;
	int column;

public:
	GridPosition();
	GridPosition(char row, int column);
	GridPosition(std::string position);
	virtual ~GridPosition();
	bool isValid()const;
	char getRow()const;
	int getColumn()const;
	operator std::string()const;
	bool operator==(GridPosition other)const;
	bool operator<(GridPosition other)const;

};

#endif /* GRIDPOSITION_H_ */
