#include "Maze.h"


Maze::Maze()
{
    initializeMaze();
}

void Maze::initializeMaze()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
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

    std::cout << line << std::endl;;

    for (int i = 0; i < 5; i++) {
        std::cout << '|';
        for (int j = 0; j < 10; j++) {
            std::cout << mazeBoard[i][j];
        }
        std::cout << '|' << std::endl;
    }

    std::cout << line << std::endl;;
}

void Maze::displayHelp()
{
    std::cout << "this is help panel ;) Hope it helped you!" << std::endl;
    system("pause");
}

void Maze::readFromFile() {
    std::fstream file{ "labirynt.txt",std::ios::in };

    std::string line;
    int j{}, i{};

    if (file.good()) {
        std::getline(file, line);
        for (size_t k{ 0 }; k < line.size(); k++) {
            if ((k + 1) % 10 == 0) {
                mazeBoard[i][j] = line[k];
                i++;
                j = 0;
            }
            else {
                mazeBoard[i][j] = line[k];
                j++;
            }
        }
    }

}

void Maze::writeToFile()
{
    std::fstream file("labirynt.txt", std::ios::out);
    //file.open("labirynt.txt",std::ios::out|std::ios::in);

    if (file.good()) {
        std::cout << "plik zostal otwarty";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                file << mazeBoard[i][j];
            }
        }
    }
    if (!file.good()) {
        std::cout << "cos nie dziala";
    }

    file.close();
}