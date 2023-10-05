#include "Engine.h"

Engine::Engine()
	: gboard()
{
	
}

char Engine::opponent(const char& piece)
{
	if (piece == 'X')
	{
		return 'O';
	}
	else
	{
		return 'X';
	}
}

char Engine::humanPiece()
{
	char go_first = askYesNo("������ ������� ������� ��� ������?");
	if (go_first == 'y')
	{
		std::cout << "\n��� ��� ���� ������!\n";
		return 'X';
	}
	else
	{
		std::cout << "\n����'���� ������ ������!\n";
		return 'O';
	}
}

void Engine::displayBoardE()
{
	gboard.displayBoard();
}

GameBoard Engine::GetBoard()
{
	return gboard;
}

bool Engine::isLegal(int move)
{
	return gboard[move] == ' ';
}

char askYesNo(const std::string& question)
{
	char response;

	do
	{
		std::cout << question << " (y/n) : ";
		std::cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int askNumber(const std::string& questoin, const int& higth, const int& low)
{
	int number;

	do
	{
		std::cout << questoin << " (" << low << " - " << higth << "): ";
		std::cin >> number;
	} while (number > higth || number < low);

	return number;
}