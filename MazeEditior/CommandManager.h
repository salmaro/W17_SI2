#pragma once
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>


class CommandManager
{
private:

	std::map<std::string, std::function<void(std::vector<std::string>)>>commandLibrary;

public:
	void registerCommand(std::string name, std::function<void(std::vector<std::string>)> func);
	void mapStringToCommand(/*std::string newCommandToMap*/);
	void invokeMethod(std::string input);

};

