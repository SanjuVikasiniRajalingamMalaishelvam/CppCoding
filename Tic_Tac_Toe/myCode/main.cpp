// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "CGame.h"


using namespace std;


// Main program
int main (void)
{
    // TODO: Add your program code here
	cout << "Tic_Tac_Toe started." << endl << endl;
	srand (time(NULL));

	/** Object for tictactoe game is created */
	CGame v1;

	/** Game is started*/
	v1.play();

	return 0;
}
