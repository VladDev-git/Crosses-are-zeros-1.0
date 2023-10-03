#include "GameBoard.h"

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
	
}
