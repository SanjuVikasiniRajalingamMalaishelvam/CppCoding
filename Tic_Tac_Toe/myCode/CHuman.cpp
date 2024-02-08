/*
 * CHuman.cpp
 *
 *  Created on: 4 Dec 2021
 *      Author: sanju
 */

#include "CHuman.h"
#include "iostream"


using namespace std;

/**
 * \brief Initializes the pointer board with the address
 *        of the Cboard
 * @param board : Pointer to the Cboard
 */
CHuman::CHuman(board_state_t player_coin, CBoard* board):CPlayer(board)
{
	row=0;
	column=0;
	m_position = player_coin;

}
/**
 * \brief Defines the API to place the coin chosen by human player.
 *  In case of invalid move , it asks the user again to enter the coordinates
 */

void CHuman::set_tile_position()
{
	int row=0;
	int column=0;
	cout<<"Enter the position"<<endl;
	cout<<"row =";
	cin>>row;
	cout<<"column =";
	cin>>column;
	while(1)
	{

		if (get_position(row, column)!= EMPTY)
		{
			cout<< "Invalid position. Already occupied. Try again"<<endl;
		}
		else if (!((row>=0) && (row<3) && (column>=0) && (column<3)))
		{
			cout<<"Invalid co-ordinates. Try again"<<endl;
		}
		else
		{
			break;
		}
		cout<<"Enter the position"<<endl;
		cout<<"row =";
		cin>>row;
		cout<<"column =";
		cin>>column;
	}
	set_position(row, column, m_position);
}
/**
 * Destructor
 */
CHuman::~CHuman()
{
}
