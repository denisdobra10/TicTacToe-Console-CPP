#define ROWS 3
#define COLUMNS 3
#define MAP_CHARACTER '-'

class GameMap
{
private:
	char map[ROWS][COLUMNS];


public:
	void InitializeMap();
	void InsertToPosition(char playerChar, int pos);
	void DisplayMap();
	char MapCharAt(int rowIndex, int colIndex);
};