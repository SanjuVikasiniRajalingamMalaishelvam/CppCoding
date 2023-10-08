/*
 * OwnGrid.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "OwnGrid.h"

using namespace std;
OwnGrid::OwnGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->shipsMap ={
			{5 , 1},//carrier
			{4,  2},//battleship
			{3,  3},//destroyer
			{2,  4}//submarine
	};
	//this->shipsMap[5] = 1;

}

OwnGrid::~OwnGrid()
{
	// TODO Auto-generated destructor stub
}

int OwnGrid::getRows() const
{
	return this->rows;
}

int OwnGrid::getColumns() const
{
	return this->columns;
}

bool OwnGrid::placeSip(const Ship &ship)
{
	bool RC = false;
	vector<GridPosition>intersection;
	int length = ship.length();
	if (ship.isValid() && (shipsMap[length]>0))
	{
		for (auto itrVec = ships.begin(); itrVec!= ships.end(); itrVec++)
		{
			std::set_intersection(ship.occupiedArea().begin(), ship.occupiedArea().end(),
					itrVec->blockedArea().begin(), itrVec->blockedArea().end(),
					std::back_inserter(intersection));
		}
		if (intersection.size()>0)
		{
			RC = false;
		}
		else
		{
			ships.push_back(Ship(ship.getBow(), ship.getStern()));
			shipsMap[length]--;
			RC = true;
		}
	}

	return RC;

}

const std::vector<Ship> OwnGrid::getShips() const
{
	return ships;
}

Impact OwnGrid::takeBlow(const Shot &shot)
{
	Impact impact = NONE;
	for (auto itr = ships.begin(); itr!= ships.end(); itr++)
	{
		for (auto OccItr = itr->occupiedArea().begin(); OccItr!= itr->occupiedArea().end(); OccItr++)
		{
			if (*OccItr ==(shot.getTargetPostion()))
			{
				impact = HIT;
				shotShips.push_back(shot.getTargetPostion());
			}

		}
	}

	if (HIT ==impact)
	{

	}

	return impact;
}

const std::vector<GridPosition> OwnGrid::getShotAt() const
{
	return this->shotShips;
}
