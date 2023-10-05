#pragma once
#include <iostream>
#include <string>
#include "GameBoard.h"

class GameBoard;

const char X_E = 'X';
const char O_E = 'O';
const char TIE_E = 'T';
const char NO_ONE_E = 'N';
const char EMPTY_E = ' ';

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
	char winnerE();
	int humanMove(char human);

	GameBoard GetBoard();

	//friend class GameBoard;
};

char askYesNo(const std::string& question);
int askNumber(const std::string& questoin, const int& higth, const int& low = 0);