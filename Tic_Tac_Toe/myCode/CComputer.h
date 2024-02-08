/*
 * CComputer.h
 *
 *  Created on: 3 Dec 2021
 *      Author: sanju
 */

#ifndef CCOMPUTER_H_
#define CCOMPUTER_H_

#include "CPlayer.h"

#define WINNING_MOVES 5

/**
 * Enumeration for the placement of movement of coin
 * Board can be empty, in corner, in edge or attack position can be placed
 */
enum Player_Move
{
	EMPTY_BOARD,
	CORNER,
	EDGE,
	ATTACKORBLOCK,
};
typedef Player_Move Player_Move_t;

/**
 * Enumeration for the tile position
 * The cor-ordinate can be zero, one or two
 * It is a 2D array
 */

enum tile_Position
{
	POSITION_ZERO,
	POSITION_ONE,
	POSITION_TWO,
};
typedef tile_Position tile_Position_t;

/**
 * Coin placement enumeration for checking the efficiency for coin placement
 * Available, unavailble, winning or not winning move
 */
enum Coin_placement
{
	UNAVAILABLE,
	AVAILABLE,
	NOT_A_WINNING_MOVE,
	IS_WINNING_MOVE,
};
typedef Coin_placement Coin_placement_t;

/**
 * Class for the computer player and is inherited from CPlayer
 * CPlayer is the base class and CComputer will be the child class
 */

class CComputer:public CPlayer
{
private:
	/**
	 * Initialization for the variables and m_position
	 */
	board_state_t m_position;
	int m_best_row;
	int m_best_column;


public:
	/**
	 * Constructor definition for computer player and player_coin is passed as a parameter
	 * It is from the CPlayer and the pointer board is used
	 */
	CComputer(board_state_t player_coin, CBoard* board);
	/**
	 * Destructor to deinitialize the variables
	 */
	~CComputer();
	/**
	 * Function definition for checking the best position
	 * @param: player_coin which is the enumeration from parent class CPlayer
	 */
	void check_best_position(board_state_t player_coin);
	/**
	 * Function definition for checking the winning condition
	 * @param: player_coin which is the enumeration from parent class CPlayer
	 */
	Coin_placement_t check_winning (board_state_t player_coin);
	/**
	 * Function definition for checking options to block or attack
	 * @param:player_coin:which is the enumeration from parent class CPlayer
	 * @param:check_move: Enumeration to check the coin placement in different positions
	 */
	Coin_placement_t Block_or_attack (board_state_t player_coin, Player_Move_t check_move);
	/**
	 * Function definition for blocking the opponent
	 * @param:player_coin: which is the enumeration from parent class CPlayer
	 * @param:check_move: Enumeration to check the coin placement in different positions
	 * @param:check_tile: enumeration for checking the position zero,one or two
	 */
	Coin_placement_t block_opponent(board_state_t player_coin,  Player_Move_t check_move, tile_Position_t check_tile );


	void set_tile_position();
};

#endif /* CCOMPUTER_H_ */
