/*
 * CComputer.cpp
 *
 *  Created on: 3 Dec 2021
 *      Author: sanju
 */

/**
 * Standard library functions
 */
#include "CComputer.h"
#include<iostream>
using namespace std;

/**
 * Constructor definition
 */
CComputer::CComputer(board_state_t player_coin, CBoard *board):CPlayer(board)
{
	m_best_row=0;
	m_best_column=0;
	m_position = player_coin;
}

CComputer::~CComputer()
{

}

void CComputer::check_best_position(board_state_t player_coin)
{
	board_state_t opp_coin = (player_coin == COIN_X)?COIN_O:COIN_X;
	if (Block_or_attack(player_coin,EMPTY_BOARD) == AVAILABLE)
	{

	}
	else if (Block_or_attack(player_coin ,ATTACKORBLOCK) == AVAILABLE)
	{

		/* Check if the computer player can win in the next move
		 * if AVAILABLE , Sets the row and column position*/
	}
	else if (Block_or_attack(opp_coin ,ATTACKORBLOCK) == AVAILABLE)
	{
		/*
		 * Check if opponent can win in the next move
		 * if AVAILABLE, sets the row and column to block opponents winning move.*/
	}
	else if (Block_or_attack(player_coin, ATTACKORBLOCK)== AVAILABLE)
	{
		/*
		 * Check if opponent trying to create chance to winning in the next move
		 * if AVAILABLE, sets the row and column to block opponents fork.*/
	}
	else if(Block_or_attack(player_coin,CORNER) == AVAILABLE)
	{
		/*
		 * Check if corner AVAILABLE , if available place in corner*/
	}
	else if(Block_or_attack(player_coin,EDGE) == AVAILABLE)
	{
		/* Check if edge AVAILABLE , if available place in edge*/
	}
}

Coin_placement_t CComputer::check_winning(board_state_t player_coin)
{

	Coin_placement_t rc = NOT_A_WINNING_MOVE;
	int checkRowFlag = 0;
	int checkColumnFlag  =0 ;
	int checkPrimaryDiagnol = 0;
	int checkSecondaryDiagnol = 0 ;

	for (int rowIndex = 0; rowIndex<3 ; rowIndex++)
	{
		checkRowFlag = 0;
		checkColumnFlag  =0;
		for (int columnIndex = 0; columnIndex<3 ; columnIndex++)
		{
			/* Check Each Row  */
			if (get_position(rowIndex, columnIndex) == player_coin)
			{
				++checkRowFlag ;
			}

			/* Check Each Column */
			if (get_position(rowIndex, columnIndex)  == player_coin)
			{
				++checkColumnFlag ;
			}

			/* Check Primary Diagonol */
			if (rowIndex == columnIndex)
			{
				if (get_position(rowIndex, columnIndex)  == player_coin)
				{
					++checkPrimaryDiagnol ;
				}
			}
			/* Check Secondary Diagonol */
			if ((rowIndex + columnIndex) == (2))
			{
				if (get_position(rowIndex, columnIndex)  == player_coin)
				{
					++checkSecondaryDiagnol ;
				}
			}
		}
		/* check if all elements in a row/column is of same tile */
		if (checkRowFlag == 3 || checkColumnFlag == 3)
		{
			rc = IS_WINNING_MOVE;
			break;
		}
	}
	/* if all elements in a primary/secondary diagonol is of same tile */
	if (checkPrimaryDiagnol == 3 || checkSecondaryDiagnol == 3)
	{
		rc = IS_WINNING_MOVE;
	}

	return rc;
}
/**
 * The computer can play on center or corner initially to maximize win Probability
 * It startes with the center and continues to corners and edges
 */

Coin_placement_t CComputer::Block_or_attack(board_state_t player_coin, Player_Move_t check_move)
{
	Coin_placement_t rc = UNAVAILABLE;
	int randomInitialVal =0 ;
	int checkBoardEmpty= 0;


	int initialPossibleMove[5][2] = {{1,1},{0, 0}, {0, 2}, {2, 0}, {2, 2}};

	for (int rowIndex = 0; rowIndex<3 ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<3 ; columnIndex++)
		{
			/**
			 * Checking for the centre (1,1)
			 */
			if ((rowIndex== 1) && (columnIndex ==1))
			{
				if (get_position(rowIndex, columnIndex)  == EMPTY)
				{
					m_best_row = rowIndex ;
					m_best_column = columnIndex ;
					rc = AVAILABLE ;
					break;
				}
			}

			/**
			 *  Checking the corner
			 */
			else if (check_move == CORNER)
			{
				if ((rowIndex % 2 == 0) && (columnIndex % 2 ==0))
				{
					if (get_position(rowIndex, columnIndex)  == EMPTY)
					{
						m_best_row = rowIndex ;
						m_best_column = columnIndex ;
						rc = AVAILABLE ;
						break;
					}
				}

			}

			/**
			 * Check for edges
			 */
			else if (check_move == EDGE)
			{
				if (((rowIndex + columnIndex) % 2) == 1)
				{
					if (get_position(rowIndex, columnIndex)  == EMPTY)
					{
						m_best_row = rowIndex ;
						m_best_column = columnIndex ;
						rc = AVAILABLE ;
						break;
					}
				}

			}
		}
		if (rc == AVAILABLE)
		{
			break;
		}
	}
	/**
	 * Generating random moves for the computer
	 */	if (checkBoardEmpty == (3*3))
	 {
		 randomInitialVal = rand () % WINNING_MOVES;
		 m_best_row = initialPossibleMove[randomInitialVal][POSITION_ZERO];
		 m_best_column = initialPossibleMove[randomInitialVal][POSITION_ONE];
		 rc =AVAILABLE;
	 }
	 return rc;
}

Coin_placement_t CComputer::block_opponent(board_state_t player_coin, Player_Move_t check_move, tile_Position_t check_tile  )
{
	Coin_placement_t rc = UNAVAILABLE;

	board_state_t opp_coin = (player_coin == COIN_X)?COIN_O:COIN_X;

	/* Check if computer player is in center block forks */

	if (get_position(POSITION_ONE,POSITION_ONE) == player_coin)
	{


		/**
		 *  Check in primary diagnol
		 */
		if ((get_position(POSITION_ONE,POSITION_ONE)== opp_coin) && (get_position(POSITION_ONE, POSITION_ONE) == opp_coin))
		{
			rc = Block_or_attack(player_coin,EDGE);
		}

		/**
		 *  Check in second diagonal
		 */
		else if((get_position(POSITION_ZERO, POSITION_TWO) == opp_coin) &&
				(get_position(POSITION_TWO, POSITION_ZERO) == opp_coin))
		{
			rc = Block_or_attack(player_coin,EDGE);
		}

		/* Block Side */
		else if((get_position(POSITION_ONE, POSITION_TWO) == opp_coin) &&
				(get_position(POSITION_TWO, POSITION_ONE) == opp_coin))
		{
			if(get_position(POSITION_TWO, POSITION_TWO) == EMPTY)
			{
				m_best_row = POSITION_TWO;
				m_best_column =POSITION_TWO;
				rc = AVAILABLE;
			}
		}
	}
	/* Check if center is empty , if empty fill center */
	if(get_position(POSITION_ONE, POSITION_ONE) == EMPTY)
	{
		m_best_row = POSITION_ONE ;
		m_best_column = POSITION_ONE ;
		rc = AVAILABLE;
	}
	return rc;
}


void CComputer::set_tile_position()
{
	check_best_position(m_position);

	if (get_position(m_best_row, m_best_column)== EMPTY)
	{
		get_position(m_best_row, m_best_column);

	}
	else
	{
		cout<<"Invalid move by computer"<<endl;
	}
	set_position(m_best_row, m_best_column, m_position);
	check_best_position(m_position);

}


