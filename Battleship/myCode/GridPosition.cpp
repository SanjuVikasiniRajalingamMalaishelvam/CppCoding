/*
 * GridPosition.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "GridPosition.h"

using namespace std;
GridPosition::GridPosition(char row, int column)
{
	this->row = row;
	this->column = column;
}

GridPosition::GridPosition(std::string position)
{
	char row =  position[0];
	int column = stoi(position.erase(0,1));

	this->row =  row;
	this->column = column;

}

GridPosition::~GridPosition()
{
	// TODO Auto-generated destructor stub
}

bool GridPosition::isValid() const
{
	if ((this->row >= 'A') && (this->row <= 'J'))
	{
		if ((this->column  > 0) && (this->column <=10))
		{
			return true;
		}
	}
	return false;
}

char GridPosition::getRow() const
{
	return this->row;
}

int GridPosition::getColumn() const
{
	return this->column;
}



bool GridPosition::operator ==(GridPosition other) const
{
	if ((this->row == other.row) && (this->column == other.column))
	{
		return true;
	}
	return false;
}

GridPosition::operator std::string() const
{
	string position = row + to_string(column);
	return position;

}

GridPosition::GridPosition()
{
	this->row = 0;
	this->column = 0;
}

bool GridPosition::operator <(GridPosition other) const
{
	if (this->row == other.row)
	{
		if (this->column < other.column)
		{
			return true;
		}
	}
	if (this->column == other.column)
	{
		if (this->row < other.row)
		{
			return true;
		}
	}
	return false;
}
