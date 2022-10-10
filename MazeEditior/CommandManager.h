#pragma once
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Maze.h"

class CommandManager
{
private:
	Maze maze;
	std::map<std::string, std::function<void(std::vector<std::string>)>>commandLibrary;

public:
	CommandManager();
	void registerCommand(std::string name, std::function<void(std::vector<std::string>)> func);
	std::string mapStringToCommand(/*std::string newCommandToMap*/);
	void invokeMethod(std::string input);
	void runProgram();

};