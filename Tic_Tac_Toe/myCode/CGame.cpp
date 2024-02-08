/*
 * CGame.cpp
 *
 *  Created on: 5 Dec 2021
 *      Author: sanju
 */
#include "CGame.h"
#include "CHuman.h"
#include "CComputer.h"
#include <iostream>

using namespace std;
/**
 * Function definition of get_players with the datatype of enumeration of player_selection
 * The player type is get from the user
 * If player is 1, it i s human
 * If player is 2, it is computer
 * Incase of invalid selection, requested to select players again
 */
player_selection_t CGame::get_players()
{

	player_selection_t player;
	int player_number;

	cout<<"Select player"<< "(Player 1 - Human, Player 2- Computer)";
	cin>>player_number;
	while(1)
	{
		if (player_number==1)
		{
			player= HUMAN_PLAYER;
			cout<<"Human Player is selected"<<endl;
			break;
		}
		else if (player_number == 2)
		{
			player=COMPUTER_PLAYER;
			cout<<"Computer player is selected"<<endl;
			break;
		}
		else
		{
			cout<<"Invalid player selection. Press again"<<endl;
		}
		cout<<"Select player"<< "(Player 1 - Human, Player 2- Computer)";
		cin>>player_number;
	}
	return player;
}

/**
 * Function definition for the player 1 assigning
 * If player1 is human, it will go to the correcponding class
 * Else to the computer class
 */

void CGame::assign_player1()
{
	if(get_players() == HUMAN_PLAYER)
	{

		m_player[1] =new CHuman(COIN_X, &m_board);
		cout<<"First player is selected as Human"<<endl;
	}
	else
	{
		m_player[1] = new CComputer(COIN_X, &m_board);
		cout<<"First player is selected as Computer"<<endl;
	}
}

/**
 * Function definition for the player 2 assigning
 * If player2 is human, it will go to the correcponding class
 * Else to the computer class
 */
void CGame::assign_player2()
{
	if(get_players() == HUMAN_PLAYER)
	{
		m_player[2] =new CHuman(COIN_O, &m_board);
		cout<<"Second player is selected as Human"<<endl;
	}
	else
	{
		m_player[2] = new CComputer(COIN_O, &m_board);
		cout<<"Second player is selected as Computer"<<endl;
	}
}

/**
 * Function definition for the tictactor game play
 * The game is played for 9 rounds.
 * At the end, the winner is displayed and incase of draw, draw is displayed
 */

void CGame::play()
{
	cout <<"Player 1 coin is X " <<endl;
	cout <<"Player 2 coin is O " <<endl;
	cout << "Lets play " <<endl;

	assign_player1();
	assign_player2();


	for(int row=0; row<3; row++)
	{
		for(int column =0; column<3; column++)
		{
			cout<<(char)m_board.get_tile_position(row, column)<<" ";
		}
		cout<<endl;
	}

	for (int rounds =0 ; rounds<9; rounds++)
	{
		cout <<endl <<"Placing a stone in round " << rounds+1 << endl;
		m_player[rounds%2+1]->set_tile_position();
		m_screen->Print_field_board(&m_board);
		if (rounds%2)
		{
			if (check_result(COIN_X) == WIN)
			{
				cout<<"There is a Winner"<<endl;
				break;
			}
		}
		else
		{
			if (check_result(COIN_O) == WIN)
			{
				cout<<"There is a Winner"<<endl;
				break;
			}
		}

	}
	cout<<"Draw"<<endl;

}

/**
 * Function definition to check the game result
 * It checks for winning in rows, columns and diagonals
 */
game_result_t CGame::check_result(board_state_t Board_state)
{

	int row=0;
	int column=0;
	int diagonalX_flag=0;
	int diagonalO_flag=0;
	int n_diagonalX_flag=0;
	int n_diagonalO_flag=0;

	game_result_t rc=IN_PROGRESS;

	for(row=0; row<3; row++)
	{
		column=0;
		if (((m_board.get_tile_position(row, column)==COIN_X) && (m_board.get_tile_position(row, (column+1))==COIN_X) && (m_board.get_tile_position(row, (column+2))==COIN_X))||
				(((m_board.get_tile_position(row, column)==COIN_O)) && (m_board.get_tile_position(row, (column+1))==COIN_O) && (m_board.get_tile_position(row, (column+2))==COIN_O)))
		{
			rc= WIN;
			break;
		}
	}

	for(column=0; column<3; column++)
	{
		row=0;
		if (((m_board.get_tile_position(row, column)==COIN_X) && (m_board.get_tile_position((row+1),column)==COIN_X) && (m_board.get_tile_position((row+2), column)==COIN_X))||
				((m_board.get_tile_position(row, column)==COIN_O) && (m_board.get_tile_position((row+1),column)==COIN_O) && (m_board.get_tile_position((row+2), column)==COIN_O)))
		{
			rc= WIN;
			break;
		}
	}
	for(row=0; row<3; row++)
	{
		for (column=0; column<3; column++)
		{
			if (row==column)
			{
				if (m_board.get_tile_position(row, column)== COIN_X)
				{
					diagonalX_flag++;
				}

				if (m_board.get_tile_position(row, column)== COIN_O)
				{
					diagonalO_flag++;
				}
			}

			if ((row==0 && column==2) || (row==1 && column==1) || (row==2 && column==0))
			{
				if (m_board.get_tile_position(row, column)== COIN_X)
				{
					n_diagonalX_flag++;
				}

				if (m_board.get_tile_position(row, column)== COIN_O)
				{
					n_diagonalO_flag++;
				}
			}
		}
	}
	if (diagonalX_flag==3 || diagonalO_flag==3 || n_diagonalX_flag==3 || n_diagonalO_flag==3)
	{
		rc= WIN;
	}
	return rc;
}
/**
 * Default constructor
 */

CGame::CGame()
{
	m_screen= new CScreen (&m_board);
}
/**
 * Destructor to deinitialize
 */
CGame::~CGame()
{
}





