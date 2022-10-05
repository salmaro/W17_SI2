#include "Maze.h"

Maze::Maze()
{
	initializeMaze();
}

void Maze::initializeMaze()
{
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 10; j++){
			mazeBoard[i][j] = ' ';
		}
	}
}

void Maze::placeCharacter(char sign, int x, int y)
{
	mazeBoard[x][y] = sign;
}

char Maze::readCharacter(int x, int y)
{
	return mazeBoard[x][y];
}
