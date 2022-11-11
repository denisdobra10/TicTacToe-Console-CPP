#include "tictactoe.h"
#include <iostream>


int main()
{
	Game game;
	game.Initialize();


	// Start game
	while (!game.gameOver)
	{
		game.DisplayMap();
		game.DisplayDetails();
		game.InsertPlayerMove();
	}

	return 0;
}