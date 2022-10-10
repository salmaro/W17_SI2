#include "CommandManager.h"

CommandManager::CommandManager() {
	auto l1 = [&](auto vec) {if (vec[0] == "start")
		maze.placeCharacter('S', std::stoi(vec[1]), std::stoi(vec[2]));
	else if (vec[0] == "end")
		maze.placeCharacter('E', std::stoi(vec[1]), std::stoi(vec[2]));
	else if (vec[0] == "wall")
		maze.placeCharacter('X', std::stoi(vec[1]), std::stoi(vec[2]));
	else if (vec[0] == "space")
		maze.placeCharacter(' ', std::stoi(vec[1]), std::stoi(vec[2]));
	};
	registerCommand("place", l1);

	auto l2 = [&](auto vec) {if (vec[0] == "help")
		maze.displayHelp();
	};
	registerCommand("help", l2);

	auto l3 = [&](auto vec) {if (vec[0] == "exit")
		exit(0);
	};
	registerCommand("exit", l3);

	auto l4 = [&](auto vec) {if (vec[0] == "write")
		maze.writeToFile();
	};
	registerCommand("write", l4);

	auto l5 = [&](auto vec) {if (vec[0] == "read")
		maze.readFromFile();
	};
	registerCommand("read", l5);
}

void CommandManager::registerCommand(std::string name, std::function<void(std::vector<std::string>)> func)
{
	if (commandLibrary.find(name) != end(commandLibrary)) {
		std::cout << "This command already exist." << std::endl;
	}
	else
		commandLibrary[name] = func;
}

std::string CommandManager::mapStringToCommand(/*std::string newCommandToMap*/)
{
	std::string input;
	std::cout << "Please enter command: " << std::endl;
	std::getline(std::cin, input);
	return input;
}

void CommandManager::invokeMethod(std::string input)
{
	std::vector<std::string> command; // {"place start 1 1"} command[0]
	std::string word;
	std::stringstream ss(input);
	while (ss >> word) {   // wyraz1 wyraz2 wyraz3
		command.push_back(word);
	}
	// komenda + argumenty
	// invoke method
	if (commandLibrary.find(command[0]) == end(commandLibrary)) {
		std::cout << "This command not exist." << std::endl;
		return;
	}
	auto cmd = commandLibrary[command[0]]; // to jest 'second' z mapy czyli lambda
	if (command.size() > 1)
		command.erase(begin(command));
	cmd(command);
}

void CommandManager::runProgram() {
	std::string input{};
	do {
		input = mapStringToCommand();
		invokeMethod(input);
		maze.displayMaze();
	} while (true);
}