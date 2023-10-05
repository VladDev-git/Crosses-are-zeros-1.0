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
	//bool isLegal(const int& move);
	//friend bool isLegal(const GameBoard& gameBoard, const int& move);

	char operator[](int index) const;
	char& operator[](int index);

	friend class Engine;
};

