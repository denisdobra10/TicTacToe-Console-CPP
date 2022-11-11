#include "gamemap.h"




class Game
{
private:
	int playerTurn;
	GameMap gameMap;
	void GetMove(int player);
	void CheckForWin(int player);
	void AskToContinue();

public:
	bool gameOver;
	int score[2];

	void Initialize();
	void DisplayMap();
	void DisplayScore();
	void DisplayScore(int player);
	void IncreaseScore();
	void DisplayDetails();

	void InsertPlayerMove();
};


