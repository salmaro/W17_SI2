#include "Maze.h"
#include <iostream>

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

void Maze::displayMaze()
{
    std::string line(12, '=');

    std::cout << line<<std::endl;;

    for (int i = 0; i < 5; i++) {
        std::cout <<'|';
        for (int j = 0; j < 10; j++) {
            std::cout << mazeBoard[i][j];
        }
        std::cout << '|' <<std::endl;
    }

    std::cout << line<< std::endl;;
}
