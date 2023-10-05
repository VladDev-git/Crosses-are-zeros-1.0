#include "Engine.h"

Engine::Engine()
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

bool Engine::isLegal(const GameBoard& board, int move)
{
	return board[move] == ' ';
}

int Engine::humanMove(const GameBoard& board, char human)
{
	int move = askNumber("������ ��� ���.", (board.board.size() - 1));
	while (!isLegal(board, move))
	{
		std::cout << "��� ��� ������������ ���� ������ ������, ������� �� ���." << std::endl;
		move = askNumber("������ ��� ���.", (board.board.size() - 1));
	}
	std::cout << "ճ� ��������.\n";

	return move;
}

int Engine::computerMove(GameBoard& board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	while (!found && move < board.board.size()) // ���� ����'���� ���� ������� ���������� ���, �� �� ���� ������ (�������� ��������)
	{
		if (isLegal(board, move))
		{
			board[move] = computer;
			found = board.winner() == computer;
			board[move] = EMPTY_E;
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

		while (!found && move < board.GetSize())
		{
			if (isLegal(board ,move))
			{
				board[move] = human;
				found = board.winner() == human;
				board[move] = EMPTY_E;
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

		while (!found && move < board.board.size())
		{
			move = BEST_MOVE[i];
			if (isLegal(board, move))
			{
				found = true;
			}
			i++;
		}
	}

	std::cout << "���'���� ������ ��� ���!";
	return move;
}

void Engine::anonceWinner(const char& winner, const char& human, const char& computer)
{
	if (winner == human)
	{
		std::cout << "³��� ������! �� ������.";
	}
	if (winner == computer)
	{
		std::cout << "����'���� ������, ����� �������� ����� ����� �� ��������� � ����������.";
	}
	else
	{
		std::cout << "ͳ���! �� �������� ����� ��������� ���������� ������.";
	}
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