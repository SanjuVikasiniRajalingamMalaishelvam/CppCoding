/*
 * CHuman.h
 *
 *  Created on: 4 Dec 2021
 *      Author: sanju
 */

#ifndef CHUMAN_H_
#define CHUMAN_H_


#include "CBoard.h"
#include "CHuman.h"
#include "CPlayer.h"

/**
 * \brief Defines the API to place the coin chosen by human player.
 *  In case of invalid move , it asks the user again to enter the coordinates
 */

class CHuman: public CPlayer
{
private:
	/**
	 * \brief Object of the m_position Class to set the coordinate for the move
	 *  by the Human player.
	 */

	board_state_t m_position;

	/**
	 * The variables row and column are initialized
	 */
	int row;
	int column;

public:

	/**
	 * \brief Initializes the pointer board with the address
	 *        of the Cboard
	 * @param board : Pointer to the Cboard
	 */
	CHuman(board_state_t player_coin, CBoard* board);
	/**
	 * Destructor
	 */
	~CHuman();
	/**
	 * \brief API to place the move of Human Player
	 * If the user enters invalid coordinate it asks the user to enter the move coordinates again
	 */
	void set_tile_position();
};

#endif /* CHUMAN_H_ */
