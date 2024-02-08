/*
 * CBoard.cpp
 *
 *  Created on: 3 Dec 2021
 *      Author: sanju
 */

#include "CBoard.h"
#include "CHuman.h"
#include "CComputer.h"
#include "CPlayer.h"
#include <iostream>

using namespace std;


/*
 * Creating for the gameboard for size 3*3
 * Default constructor
 */
CBoard::CBoard()
{
	m_rows=3;
	m_columns=3;
	m_player=0;
	current_player=0;
	opp_player=0;
	p_board=NULL;
	for (int rows=0; rows<3; rows++)
		{
			for(int columns=0; columns<3; columns++)
			{
				m_board [rows][columns]= EMPTY;
			}
		}
}
/**
 * Initialising the rows and columns in the paramatrized constructor
 */
CBoard::CBoard(int rows, int columns)
{

	m_rows=rows;
	m_columns=columns;
	m_player=0;
	current_player=0;
	opp_player=0;
	p_board=NULL;

	for (int rows=0; rows<3; rows++)
	{
		for(int columns=0; columns<3; columns++)
		{

			m_board [rows][columns]= EMPTY;
		}
	}
}

/**
 * Destructor to deinitialize all the variables
 */
CBoard::~CBoard()
{
}

/**
 * Printing the board and initializing the board as empty
 */
void CBoard::print_board()
{
	for (int rows=0; rows<3; rows++)
	{
		for(int columns=0; columns<3; columns++)
		{
			m_board[columns][rows] = EMPTY;
			cout << "" << m_board[columns][rows];
			cout<< "\t";
		}
		cout<<endl;
	}

}

/**
 * Getting the tile position of rows and columns
 */

board_state_t CBoard::get_tile_position(int row, int column)
{
	return m_board[row][column];
}

/**
 * Setting the tile position of rows and columns to the board enumeration
 */

void CBoard::set_tile_position(int row, int column, board_state_t Board_state)
{

	m_board[row][column]=Board_state;
}




