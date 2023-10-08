/*
 * OpponentGrid.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <iostream>
#include <string>

class OpponentGrid
{
private:
	int rows;
	int columns;
	//sunkenShips
public:
	OpponentGrid(int rows, int columns);
	virtual ~OpponentGrid();
	int getRows()const;
	int getColumns()const;
};

#endif /* OPPONENTGRID_H_ */
