/*
 * CBoard_Console_View.cpp
 *
 *  Created on: 5 Dec 2021
 *      Author: sanju
 */

#include "CScreen.h"

#include "CBoard.h"

/**
 * For all the co-ordinates or the board, the tictactoe board is printed
 */

CScreen::CScreen(CBoard* board)
{
	m_board= board;
}


CScreen::~CScreen()
{
}

void CScreen::Print_field_board(CBoard *pRB)
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<(char)m_board->get_tile_position(i,j)<< " ";
		}
		cout<<"\n";
	}
}

