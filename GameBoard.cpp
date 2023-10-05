#include "GameBoard.h"
#include "Engine.h"

GameBoard::GameBoard()
	: board(9, ' ')
{

}

void GameBoard::displayBoard()
{
	std::cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	std::cout << "\n\t" << "---------";
	std::cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	std::cout << "\n\t" << "---------";
	std::cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	std::cout << "\n\n";
}

char GameBoard::winner()
{
	return 0;
}

char GameBoard::operator[](int index) const
{
	if (index <= 0 && index < board.size())
	{
		return board[index];
	}
	else
	{
		return '0';
	}
}

char& GameBoard::operator[](int index)
{
	if (index <= 0 && index < board.size())
	{
		return board[index];
	}
	else
	{
		static char s = '0';
		return s;
	}
}
