/*
 * OpponentGrid.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "OpponentGrid.h"

using namespace std;

OpponentGrid::OpponentGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

OpponentGrid::~OpponentGrid()
{
	// TODO Auto-generated destructor stub
}

int OpponentGrid::getRows() const
{
	return this->rows;
}

int OpponentGrid::getColumns() const
{
	return this->columns;
}
