/*
 * CGame.h
 *
 *  Created on: 5 Dec 2021
 *      Author: sanju
 */

#ifndef CGAME_H_
#define CGAME_H_

#include "CBoard.h"
#include "CPlayer.h"
#include "CScreen.h"
#include <map>

/**
 * \brief The class CGame implements the game play logic of tictactoe Game.
 *  Each player will take turns and the player can be either human or computer
 *  if the player has won or game is draw the result is displayed on the screen.
 */
class CGame
{
private:

	/**
	 * \brief Object of the CBoard Class to set the m_board
	 */
	CBoard m_board;
	/**
	 * \brief Pointer of m_screen to store the address of the board.
	 */
	CScreen* m_screen;
	std::map<int, CPlayer*> m_player;


public:
	/**
	 * Default Constructor that initializes the pointer m_ticTacToeBoard
	 */
	CGame();
	/**
	 * Function declaration of get_players with the datatype of enumeration of player_selection
	 */
	player_selection_t get_players();
	/**
	 * Function declaration for assigning the first player
	 */
	void assign_player1();
	/**
	 * Function declaration for assigning the second player
	 */
	void assign_player2();
	/**
	 * Function declaration for the game play
	 */
	void play ();
	game_result_t check_result(board_state_t Board_state);


	~CGame();
};



#endif /* CGAME_H_ */
