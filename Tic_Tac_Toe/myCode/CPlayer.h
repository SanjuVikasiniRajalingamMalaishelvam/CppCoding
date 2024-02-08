/*
 * CPlayer.h
 *
 *  Created on: 5 Dec 2021
 *      Author: sanju
 */

#ifndef CPLAYER_H_
#define CPLAYER_H_

#include "CBoard.h"
class CBoard;

/**
 * Enumeration for player selection
 * Human player or computer player enum is selected
 */
enum player_selection
{
	HUMAN_PLAYER,
	COMPUTER_PLAYER
};
typedef player_selection player_selection_t;


/**
 * Class for CPlayer that acts as the base class
 * for human player and computer player
 */

class CPlayer
{
private:
	int row;
	int column;
	CBoard *m_position;

public:
	/**
	 * Constructor CPlayer - Default
	 */
	CPlayer(CBoard* board);
	/**
	 * Function declaration to get the tile position for placing the stones
	 */
	board_state_t get_position(int row, int column);
	/**
	 * Function declaration to set the tile position
	 */
	void set_position(int row, int column, board_state_t Board_state);

	virtual void set_tile_position()=0;
	virtual ~CPlayer();

};



#endif /* CPLAYER_H_ */
