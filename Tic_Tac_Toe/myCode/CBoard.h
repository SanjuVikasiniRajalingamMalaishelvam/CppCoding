/*
 * CBoard.h
 *
 *  Created on: 3 Dec 2021
 *      Author: sanju
 */

#ifndef CBOARD_H_
#define CBOARD_H_

/**
 * Enumeration for the state of board
 * For empty, coin x and coin o
 */
enum Board_state
{
	EMPTY ='.',
	COIN_X ='X',
	COIN_O ='O',
};
typedef Board_state board_state_t;

/**
 * Enumeration for the game result
 * For winning, progress state and draw match
 */

enum game_result
{
	WIN,
	IN_PROGRESS,
	DRAW,
};
typedef game_result game_result_t;

/**
 * Class for the Tictactoc board and variables are declared
 */
class CBoard
{
private:
	int m_rows;
	int m_columns;
	int m_player;
	int current_player;
	int opp_player;


public:
	/**
	 * Default constructor for the tictactor board
	 */
	CBoard();
	/**
	 * Parametrized constructor with the parameters.
	 * Used for variable initialization
	 * @param : row, column
	 */
	CBoard(int rows,int columns);
	/**
	 * Destructor for the tictactoe board
	 */
	virtual ~CBoard();
	/**
	 * Tictactoe board with the EMPTY enumeration
	 */
	board_state_t m_board[3][3];
	/**
	 * Function declaration for the board printing
	 */
	void print_board();
	/**
	 * Function declaration for getting the tile position to change in the board
	 */
	board_state_t get_tile_position(int, int);
	/**
	 * Setting the tile position with the enumeration for the board state
	 */
	void set_tile_position(int, int, board_state_t);

protected:

	board_state_t **p_board;

};

#endif /* REVERSIBOARD_H_ */
