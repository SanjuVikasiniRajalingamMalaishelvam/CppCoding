/*
 * Shot.h
 *
 *  Created on: 12 Feb 2023
 *      Author: sanju
 */

#ifndef SHOT_H_
#define SHOT_H_

#include <iostream>
#include <string>
#include "GridPosition.h"

typedef enum
{
	NONE,
	HIT,
	SUNKEN
}Impact;
class Shot
{
private:
	GridPosition targetPosition;
public:
	Shot(GridPosition targetPosition);
	virtual ~Shot();
	GridPosition getTargetPostion()const;

};

#endif /* SHOT_H_ */
