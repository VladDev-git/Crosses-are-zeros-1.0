#pragma once
#include <iostream>
#include <vector>

class Engine;

class GameBoard
{
private:

	std::vector<char> board;
public:

	GameBoard();

	void displayBoard();
	char winner();

	char operator[](int index) const;
	char& operator[](int index);

	friend class Engine;
};

