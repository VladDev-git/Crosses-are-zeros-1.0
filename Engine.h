#pragma once
#include "GameBoard.h"
#include <iostream>
#include <string>

//class GameBoard;

class Engine
{
private:

	GameBoard gboard;
public:

	Engine();
	char askYesNo(const std::string& question);
	int askNumber(const std::string& questoin, const int& higth, const int& low = 0);
	char
};

