/*
 * Ship.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef SHIP_H_
#define SHIP_H_


#include <iostream>
#include <string>
#include <set>
#include "GridPosition.h"

class Ship
{
private:
	GridPosition bow;
	GridPosition stern;
public:
	Ship(const GridPosition& bow, const GridPosition& stern);
	virtual ~Ship();
	bool isValid()const;
	GridPosition getBow()const;
	GridPosition getStern()const;
	int length()const;
	const std::set<GridPosition> occupiedArea()const;
	const std::set<GridPosition> blockedArea()const;

};

#endif /* SHIP_H_ */
