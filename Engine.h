#pragma once
#include <iostream>
#include <string>
#include "GameBoard.h"

class GameBoard;

class Engine
{
private:

	GameBoard gboard;
public:

	Engine();
	char opponent(const char& piece);
	char humanPiece();
	void displayBoardE();
	bool isLegal(int move);

	GameBoard GetBoard();

	friend class GameBoard;
};

char askYesNo(const std::string& question);
int askNumber(const std::string& questoin, const int& higth, const int& low = 0);