#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>

const char X = 'X';
const char O = 'O';
const char TIE = 'T';
const char NO_ONE = 'N';
const char EMPTY = ' ';
//tb thio

void instruction();
char askYesNo(const std::string& question);
int askNumer(const std::string& question, int high, int low = 0);
char humanPiece();
char opponent(char& piece);
void displayBoard(const std::vector<char>& board);
char winner(const std::vector<char>& board);
inline bool isLegal(int move, const std::vector<char>& board);
int humanMove(const std::vector<char>& board, char human);
int computerMove(std::vector<char> board, char computer);
void anonceWinner(const char& winner, const char& human, const char& computer);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int move = 0;
	const int NUM_SQUARES = 9;
	std::vector<char> board(NUM_SQUARES, EMPTY);

	instruction();

	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;

	displayBoard(board);

	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else if (turn == computer)
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	anonceWinner(winner(board), human, computer);
	return 0;
}

void instruction()
{
	std::cout << "Ласкамо просимо у найінтелектуальнішу гру Хркстики-нулики." << std::endl;
	std::cout << "Тут ти, шкіряний недоумок, зможеш позмагатися з комп'ютером." << std::endl;
	std::cout << "Щоб зробити хід потрібно вибрати число від 0 до 8" << std::endl;
	std::cout << "Число відповідає положенню на ігровій дошці, як це показано на малюнку:\n" << std::endl;
	std::cout << " 0 | 1 | 2 \n";
	std::cout << " ----------\n";
	std::cout << " 3 | 4 | 5 \n";
	std::cout << " ----------\n";
	std::cout << " 6 | 7 | 8 \n\n";
	std::cout << "Приготуйся шкіряний, бій от от почнеться!\n\n";
}

char askYesNo(const std::string& question)
{
	char response;

	do
	{
		std::cout << question << " (y/n): ";
		std::cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int askNumer(const std::string& question, int high, int low)
{
	int number;
	
	do
	{
		std::cout << question << " (" << low << " - " << high << "): ";
		std::cin >> number;
	} while (number > high || number < low);

	return number;
}

char humanPiece()
{
	char go_first = askYesNo("Бажаєте ходити першим?");

	if (go_first == 'y')
	{
		std::cout << "Ваш хід буде першим.\n";
		return X;
	}
	else
	{
		std::cout << "Ваш хід буде другим.\n";
		return O;
	}
}

char opponent(char& piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void displayBoard(const std::vector<char>& board)
{
	std::cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	std::cout << "\n\t" << "---------";
	std::cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	std::cout << "\n\t" << "---------";
	std::cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	std::cout << "\n\n";
}

char winner(const std::vector<char>& board)
{
	const int WINING_ROWS[8][3] = { // Виграшні ряди
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};

	const int TOTAL_ROWS = 8;
	for (auto row = 0; row < TOTAL_ROWS; ++row) // Пошук виграшних рядів на ігровому полі
	{
		if ((board[WINING_ROWS[row][0]] != EMPTY) &&
			(board[WINING_ROWS[row][0]] == board[WINING_ROWS[row][1]]) &&
			(board[WINING_ROWS[row][1]] == board[WINING_ROWS[row][2]]))
		{
			return board[WINING_ROWS[row][0]];
		}
	}

	if (std::count(board.begin(), board.end(), EMPTY) == 0) // Якщо переможця немає, перевіряємо чи не наступила нічия
	{			                                            // тобто, чи залишились на полі пусті клітинки
		return TIE;
	}

	return NO_ONE; // Якщо ні одна з умов завершення гри не виконалась то повертається NO_ONE і гра продовжується
}

inline bool isLegal(int move, const std::vector<char>& board)
{
	return (board[move] == EMPTY);
}

int humanMove(const std::vector<char>& board, char human)
{
	int move = askNumer("Зробіть свій хід.", (board.size() - 1));
	while (!isLegal(move, board))
	{
		std::cout << "Твій хід неправильний тупа шкіряна істото, спробуй ще раз." << std::endl;
		move = askNumer("Зробіть свій хід.", (board.size() - 1));
	}
	std::cout << "Хід зроблено.\n";

	return move;
}

int computerMove(std::vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	while (!found && move < board.size()) // Якщо комп'ютер може зробити переможний хід, то він його робить (Найвищий приорітет)
	{
		if (isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
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

		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
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

		while (!found && move < board.size())
		{
			move = BEST_MOVE[i];
			if (isLegal(move, board))
			{
				found = true;
			}
			i++;
		}
	}

	std::cout << "Коп'ютер зробив свій хід!";
	return move;
}

void anonceWinner(const char& winner, const char& human, const char& computer)
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
