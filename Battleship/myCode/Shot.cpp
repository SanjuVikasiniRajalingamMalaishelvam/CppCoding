/*
 * Shot.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#include "Shot.h"


Shot::Shot(GridPosition targetPosition)
{
	this->targetPosition = targetPosition;
}

Shot::~Shot()
{
	// TODO Auto-generated destructor stub
}

GridPosition Shot::getTargetPostion() const
{
	return this->targetPosition;
}
