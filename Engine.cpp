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
	char go_first = askYesNo("Бажаєте зробити зробити хід першим?");
	if (go_first == 'y')
	{
		std::cout << "\nВаш хід буде першим!\n";
		return 'X';
	}
	else
	{
		std::cout << "\nКомп'ютер ходить першим!\n";
		return 'O';
	}
}

bool Engine::isLegal(const GameBoard& board, int move)
{
	return board[move] == ' ';
}

int Engine::humanMove(const GameBoard& board, char human)
{
	int move = askNumber("Зробіть свій хід.", (board.board.size() - 1));
	while (!isLegal(board, move))
	{
		std::cout << "Твій хід неправильний тупа шкіряна істото, спробуй ще раз." << std::endl;
		move = askNumber("Зробіть свій хід.", (board.board.size() - 1));
	}
	std::cout << "Хід зроблено.\n";

	return move;
}

int Engine::computerMove(GameBoard& board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	while (!found && move < board.board.size()) // Якщо комп'ютер може зробити переможний хід, то він його робить (Найвищий приорітет)
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

	std::cout << "Коп'ютер зробив свій хід!";
	return move;
}

void Engine::anonceWinner(const char& winner, const char& human, const char& computer)
{
	if (winner == human)
	{
		std::cout << "Вітаю людино! Ти переміг.";
	}
	if (winner == computer)
	{
		std::cout << "Комп'ютер переміг, твоєму шкіряному мозку ніколи не зрівнятись з процесором.";
	}
	else
	{
		std::cout << "Нічия! Ти виявився доволі достойним суперником людино.";
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