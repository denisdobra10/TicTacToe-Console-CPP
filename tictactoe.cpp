#include "tictactoe.h"
#include "denishelper.h"
#include <iostream>
#include <time.h>


void Game::GetMove(int player)
{
	char userInput = 'u';

	// Read user input and check if it is a digit or not (for position)
	while (!(isdigit(userInput)))
	{
		std::cout << "->";
		std::cin >> userInput;
	}

	if (userInput == '0')
	{
		print("0 is not a valid option!");
		return;
	}

	int position = String::toint(&userInput);

	if (player == 0)
		gameMap.InsertToPosition('X', position);
	else if (player == 1)
		gameMap.InsertToPosition('0', position);
	else
		print("Error");


	print("\n\n");

}

void Game::AskToContinue()
{
	char userInput = 'u';

	print("Do you want to continue the game?(yes or no)");
	while (userInput != 'y' && userInput != 'n')
		std::cin >> userInput;

	if (userInput == 'y')
	{
		gameMap.InitializeMap();
		gameOver = false;
	}
}

void Game::CheckForWin(int player)
{
	if ((gameMap.MapCharAt(0, 0) == gameMap.MapCharAt(0, 1) && (gameMap.MapCharAt(0, 1) == gameMap.MapCharAt(0, 2))) ||
		(gameMap.MapCharAt(1, 0) == gameMap.MapCharAt(1, 1) && (gameMap.MapCharAt(1, 1) == gameMap.MapCharAt(1, 2))) ||
		(gameMap.MapCharAt(2, 0) == gameMap.MapCharAt(2, 1) && (gameMap.MapCharAt(2, 1) == gameMap.MapCharAt(2, 2))) ||
		(gameMap.MapCharAt(0, 0) == gameMap.MapCharAt(1, 0) && (gameMap.MapCharAt(1, 0) == gameMap.MapCharAt(2, 0))) ||
		(gameMap.MapCharAt(0, 1) == gameMap.MapCharAt(1, 1) && (gameMap.MapCharAt(1, 1) == gameMap.MapCharAt(2, 1))) ||
		(gameMap.MapCharAt(0, 2) == gameMap.MapCharAt(1, 2) && (gameMap.MapCharAt(1, 2) == gameMap.MapCharAt(2, 2))) ||
		(gameMap.MapCharAt(0, 0) == gameMap.MapCharAt(1, 1) && (gameMap.MapCharAt(1, 1) == gameMap.MapCharAt(2, 2))) ||
		(gameMap.MapCharAt(0, 2) == gameMap.MapCharAt(1, 1) && (gameMap.MapCharAt(1, 1) == gameMap.MapCharAt(2, 0))))
	{
		gameOver = true;


		if (player == 0)
		{
			std::cout << "Player X won!\n";
			score[0]++;
		}
		else
		{
			std::cout << "Player 0 won!\n";
			score[1]++;
		}

		AskToContinue();
	}
	else
	{
		// Change player turn
		if (playerTurn == 0)
			playerTurn = 1;
		else
			playerTurn = 0;
	}

}


void Game::Initialize()
{
	gameOver = false;

	// Initialize map
	gameMap.InitializeMap();

	// Random player start
	std::srand(time(NULL));
	playerTurn = std::rand() % 2;

	// Initialize score for player X and player 0
	score[0] = 0;
	score[1] = 0;
}

void Game::DisplayMap()
{
	gameMap.DisplayMap();
}

void Game::IncreaseScore()
{
	switch (playerTurn)
	{
	case 0:
		score[0]++;
		break;
	case 1:
		score[1]++;
		break;
	default:
		print("ERROR occured! Error details: incorrect value for variable -player- on method -IncreaseScore()- in class -Game-");
		break;
	}
}

void Game::DisplayScore()
{
	std::cout << "Player X: " << score[0] << "\nPlayer 0: " << score[1] << "\n";
}

void Game::DisplayScore(int player)
{
	if (player == 0)
		std::cout << "Player X: " << score[0] << "\n";
	else if (player == 1)
		std::cout << "Player 0: " << score[1] << "\n";
	else
		print("ERROR occured! Error details: incorrect value for variable -player- on method -DisplayScore(int player)- in class -Game-");

}

void Game::InsertPlayerMove()
{
	GetMove(playerTurn);

	CheckForWin(playerTurn);


}

void Game::DisplayDetails()
{
	std::cout << "Score:\nPlayer X: " << score[0] << "\nPlayer 0: " << score[1] << "\n--------------\n";
	switch (playerTurn)
	{
	case 0:
		print("Player X turn\n--------------\nEnter desired position(1-9)\n\n");
		break;
	case 1:
		print("Player 0 turn\n--------------\nEnter desired position(1-9)\n\n");
		break;
	default:
		break;
	}
}


