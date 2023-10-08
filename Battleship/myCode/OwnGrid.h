/*
 * OwnGrid.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Ship.h"
#include "Shot.h"

class OwnGrid
{
private:
	int rows;
	int columns;
	std::vector<Ship> ships;
	std::vector<GridPosition>shotShips;
	std::map<int, int>shipsMap;
public:
	OwnGrid(int rows, int columns);
	virtual ~OwnGrid();
	int getRows()const;
	int getColumns()const;
	bool placeSip(const Ship& ship);
	const std::vector<Ship> getShips()const;
	Impact takeBlow(const Shot& shot);
	const std::vector<GridPosition> getShotAt() const;
};

#endif /* OWNGRID_H_ */
