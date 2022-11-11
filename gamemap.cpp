#include "gamemap.h"
#include <iostream>




void GameMap::InitializeMap()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			map[i][j] = MAP_CHARACTER;
		}
	}
}

void GameMap::DisplayMap()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			std::cout << map[i][j] << " ";
		}

		std::cout << "\n";
	}
}

void GameMap::InsertToPosition(char playerChar, int pos)
{
	int counter = 1;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (counter == pos)
			{
				if (map[i][j] == MAP_CHARACTER)
				{
					map[i][j] = playerChar;
					return;
				}
				else
					std::cout << "Invalid position! Position is already taken!\n";
			}
			else
				counter++;
		}
	}
}

char GameMap::MapCharAt(int rowIndex, int colIndex)
{
	// Check letter to avoid returning map character
	if (map[rowIndex][colIndex] == MAP_CHARACTER)
		return char(std::rand() % 100 + 96);

	return map[rowIndex][colIndex];
}