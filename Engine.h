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

	
public:

	Engine();
	char opponent(const char& piece);
	char humanPiece();
	bool isLegal(const GameBoard& board, int move);
	int humanMove(const GameBoard& board, char human);
	int computerMove(GameBoard& board, char computer);
	void anonceWinner(const char& winner, const char& human, const char& computer);
};

char askYesNo(const std::string& question);
int askNumber(const std::string& questoin, const int& higth, const int& low = 0);