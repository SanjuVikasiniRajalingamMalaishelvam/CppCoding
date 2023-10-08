/*
 * Ship.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Ship.h"

using namespace std;
Ship::Ship(const GridPosition &bow, const GridPosition &stern)
{
	this->bow = bow;
	this->stern = stern;
}

Ship::~Ship()
{
	// TODO Auto-generated destructor stub
}

bool Ship::isValid() const
{
	bool RC = false;
	if (this->bow.isValid() && this->stern.isValid())
	{
		if (bow.getRow() == stern.getRow())
		{
			cout << "Ship is placed horizontally";
			RC = true;
		}
		if(bow.getColumn() == stern.getColumn())
		{
			cout << "Ship is placed vertically" <<endl;
			RC = true;
		}
	}

	return RC;
}

GridPosition Ship::getBow() const
{
	return this->bow;
}

GridPosition Ship::getStern() const
{
	return this->stern;
}

int Ship::length() const
{
	int shipLength = 0;
	if (isValid())
	{
		if (bow.getRow() == stern.getRow())
		{
			shipLength = abs(stern.getColumn()- bow.getColumn());
		}
		if (bow.getColumn() == stern.getColumn())
		{
			shipLength = abs(bow.getRow()- stern.getRow());
		}
	}
	return shipLength+1;
}

const std::set<GridPosition> Ship::occupiedArea() const
{
	set<GridPosition> occupiedArea;
	int legnth = length();
	if (bow.getRow() == stern.getRow())
	{
		if (bow.getColumn() < stern.getColumn())
		{
			for (int idx = 0; idx < legnth; idx++)
			{
				occupiedArea.insert(GridPosition(bow.getRow(), bow.getColumn()+idx));
			}
		}
		else
		{
			for (int idx = 0; idx < legnth; idx++)
			{
				occupiedArea.insert(GridPosition(bow.getRow(), stern.getColumn()+idx));
			}
		}
	}
	if (bow.getColumn() == stern.getColumn())
	{
		if (bow.getRow() < stern.getRow())
		{
			for (int idx = 0; idx < legnth; idx++)
			{
				occupiedArea.insert(GridPosition(char(bow.getRow()+idx), bow.getColumn()));
			}
		}
		else
		{
			for (int idx = 0; idx < legnth; idx++)
			{
				occupiedArea.insert(GridPosition(char(stern.getRow()+idx), bow.getColumn()));
			}
		}
	}

	return occupiedArea;
}

const std::set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> occupied = occupiedArea();
	set<GridPosition> blocked;
	for (auto itrOcc = occupied.begin(); itrOcc!= occupied.end(); itrOcc++)
	{
		for (int blockRow = itrOcc->getRow()-'A'; blockRow <= itrOcc->getRow()+'A'; blockRow++)
		{
			for (int blockCol = itrOcc->getColumn()-1; blockCol < itrOcc->getColumn()+1; blockCol++)
			{
				blocked.insert(GridPosition(blockRow, blockCol));
			}
		}
	}

	return blocked;
}
