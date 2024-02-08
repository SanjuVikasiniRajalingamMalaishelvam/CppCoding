/*
 * CPlayer.cpp
 *
 *  Created on: 5 Dec 2021
 *      Author: sanju
 */

#include "CPlayer.h"
#include <stdlib.h>
#include "iostream"

using namespace std;

/**
 *  Constructor CPlayer - Default
 */
CPlayer::CPlayer(CBoard* board)
{
	row=3;
	column=3;
	m_position = board;
}

/**
 * Destructor to deinitialize
 */
CPlayer::~CPlayer()
{
}

/**
 * Function definition to get the row and column to place or set the stone
 */
board_state_t CPlayer::get_position(int row, int column)
{
	return m_position->get_tile_position(row, column);
}

/**
 * Function defnition to set the stone in the already got tile positions
 */

void CPlayer::set_position(int row, int column, board_state_t Board_state)
{
	m_position->set_tile_position(row, column, Board_state);
}





