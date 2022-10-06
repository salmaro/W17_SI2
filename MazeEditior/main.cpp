#include "CommandManager.h"
#include "Maze.h"
#include <iostream>

int main()
{
	//std::vector<std::string> vec{ "moja", "pierwsza", "komenda" };
	//auto l1 = [](auto vec) {for (auto e: vec) std::cout << e;};
	//CommandManager cmd;
	//cmd.registerCommand("test", l1);
	//cmd.mapStringToCommand();

	Maze labirynt;
	labirynt.displayMaze();

	return 0;
}