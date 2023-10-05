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
	const int WINING_ROWS[8][3] = { // ¬играшн≥ р€ди
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
	for (auto row = 0; row < TOTAL_ROWS; ++row) // ѕошук виграшних р€д≥в на ≥гровому пол≥
	{
		if ((board[WINING_ROWS[row][0]] != EMPTY_E) &&
			(board[WINING_ROWS[row][0]] == board[WINING_ROWS[row][1]]) &&
			(board[WINING_ROWS[row][1]] == board[WINING_ROWS[row][2]]))
		{
			return board[WINING_ROWS[row][0]];
		}
	}

	if (std::count(board.begin(), board.end(), EMPTY_E) == 0) // якщо переможц€ немаЇ, перев≥р€Їмо чи не наступила н≥чи€
	{			                                            // тобто, чи залишились на пол≥ пуст≥ кл≥тинки
		return TIE_E;
	}

	return NO_ONE_E; // якщо н≥ одна з умов завершенн€ гри не виконалась то повертаЇтьс€ NO_ONE ≥ гра продовжуЇтьс€
}

size_t GameBoard::GetSize()
{
	return board.size();
}

char GameBoard::operator[](int index) const
{
	if (index >= 0 && index < board.size())
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
	if (index >= 0 && index < board.size())
	{
		return board[index];
	}
	else
	{
		static char s = '0';
		return s;
	}
}
