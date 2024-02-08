/*
 * CBoard_Console_View.h
 *
 *  Created on: 5 Dec 2021
 *      Author: sanju
 */

#ifndef CSCREEN_H_
#define CSCREEN_H_
#include <iostream>
#include <stdlib.h>
#include "CBoard.h"


using namespace std;

/**
 * Class CScreen to call the CBoard class using a pointer pRB and prints the tictactoe board
 */
class CScreen
{
private:


	CBoard *m_board;

public:
	/**
	 * Default constructor
	 */
	CScreen(CBoard* board);
	virtual ~CScreen();

	/**
	 * Prints the tictactoe board by a pointer as an object to the previous class
	 */
	void Print_field_board(CBoard* pRB);

};





#endif /* CSCREEN_H_ */
