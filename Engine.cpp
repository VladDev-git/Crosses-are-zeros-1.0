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

char Engine::winnerE()
{
	return gboard.winner();
}

int Engine::humanMove(char human)
{
	int move = askNumber("������ ��� ���.", (gboard.GetSize() - 1));
	while (!isLegal(move))
	{
		std::cout << "��� ��� ������������ ���� ������ ������, ������� �� ���." << std::endl;
		move = askNumber("������ ��� ���.", (gboard.GetSize() - 1));
	}
	std::cout << "ճ� ��������.\n";

	return move;
}

int Engine::computerMove(char computer)
{
	unsigned int move = 0;
	bool found = false;

	while (!found && move < gboard.GetSize()) // ���� ����'���� ���� ������� ���������� ���, �� �� ���� ������ (�������� ��������)
	{
		if (isLegal(move))
		{
			gboard[move] = computer;
			found = winnerE() == computer;
			gboard[move] = EMPTY_E;
		}
		if (!found)
		{
			move++;
		}
	}

	if (!found)
	{
		move = 0;
		char human = opponent(computer);

		while (!found && move < gboard.GetSize())
		{
			if (isLegal(move))
			{
				gboard[move] = human;
				found = winnerE() == human;
				gboard[move] = EMPTY_E;
			}
			if (!found)
			{
				move++;
			}
		}
	}

	if (!found)
	{
		move = 0;
		unsigned int i = 0;
		std::vector<int> BEST_MOVE {4, 0, 2, 6, 8, 1, 3, 5, 7};

		while (!found && move < gboard.GetSize())
		{
			move = BEST_MOVE[i];
			if (isLegal(move))
			{
				found = true;
			}
			i++;
		}
	}

	std::cout << "���'���� ������ ��� ���!";
	return move;
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