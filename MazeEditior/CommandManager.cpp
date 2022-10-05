#include "CommandManager.h"

void CommandManager::registerCommand(std::string name, std::function<void(std::vector<std::string>)> func)
{
	if (commandLibrary.find(name) != end(commandLibrary)) {
		std::cout << "This command already exist." << std::endl;
	}
	else
		commandLibrary[name] = func;
}

void CommandManager::mapStringToCommand(/*std::string newCommandToMap*/)
{
	std::string input;
	while (input != "exit") {
		std::cout << "Please enter command: " << std::endl;
		std::getline(std::cin, input);
		invokeMethod(input);
	}
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
	command.erase(begin(command));
	cmd(command);
}
