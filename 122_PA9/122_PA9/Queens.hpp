#pragma once

#include "ChessPieces.hpp"


class Queens : public ChessPieces
{
public:
	Queens(void);
	 ~Queens(void);

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Queens::Queens()
{
	tex.loadFromFile("White Queen.png");
	this->setTexture(&tex);
}

Queens::~Queens()
{

}

void Queens::killOpponentPiece()
{

}

bool Queens::move()
{
	return true;
}


bool Queens::checkPath()
{
	return false;
}

int Queens::checkIfCheckmate() // returns 0 if no, 1 if check, 2 if checkmate
{
	return 0;
}