﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
// classes
#include "GameBoard.h"
#include "Engine.h"

const char X = 'X';
const char O = 'O';
const char TIE = 'T';
const char NO_ONE = 'N';
const char EMPTY = ' ';

//void instruction();                                                              +
//char askYesNo(const std::string& question);                                      +
//int askNumer(const std::string& question, int high, int low = 0);                +
//char humanPiece();                                                               +
//char opponent(char& piece);                                                      +
//void displayBoard(const std::vector<char>& board);                               +
//char winner(const std::vector<char>& board);                                     +
//inline bool isLegal(int move, const std::vector<char>& board);                   +
//int humanMove(const std::vector<char>& board, char human);                       +
//int computerMove(std::vector<char> board, char computer);                        +
//void anonceWinner(const char& winner, const char& human, const char& computer);  +

void instruction();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GameBoard board;
	Engine engine;
	int move = 0;

	instruction();

	char human = engine.humanPiece();
	char computer = engine.opponent(human);
	char turn = X;
	board.displayBoard();

	while (board.winner() == NO_ONE)
	{
		if (turn == human)
		{
			move = engine.humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = engine.computerMove(board, computer);
			board[move] = computer;
		}
		board.displayBoard();
		turn = engine.opponent(turn);
	}
	engine.anonceWinner(board.winner(), human, computer);
	 
	return 0;
}

void instruction()
{
	std::cout << "Ласкамо просимо у найінтелектуальнішу гру Хркстики-нулики." << std::endl;
	std::cout << "Тут ти, представник людської раси, зможеш позмагатися з комп'ютером." << std::endl;
	std::cout << "Щоб зробити хід потрібно вибрати число від 0 до 8" << std::endl;
	std::cout << "Число відповідає положенню на ігровій дошці, як це показано на малюнку:\n" << std::endl;
	std::cout << " 0 | 1 | 2 \n";
	std::cout << " ----------\n";
	std::cout << " 3 | 4 | 5 \n";
	std::cout << " ----------\n";
	std::cout << " 6 | 7 | 8 \n\n";
	std::cout << "Приготуйся людино, бій от от почнеться!\n\n";
}
