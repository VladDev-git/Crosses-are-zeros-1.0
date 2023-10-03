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
};

