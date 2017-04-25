#pragma once

#include "ChessPieces.hpp"

class Bishops : public ChessPieces
{
public:
	Bishops();
	~Bishops();

	void killOpponentPiece();

	bool move();

	bool checkPath();

	int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:
	
};

Bishops::Bishops()
{
	tex.loadFromFile("White Bishop.png");
	this->setTexture(&tex);

	type = 'B';
}

Bishops::~Bishops()
{

}

void Bishops::killOpponentPiece()
{

}

bool Bishops::move()
{
	return true;
}


bool Bishops::checkPath()
{
	return false;
}

int Bishops::checkIfCheckmate() // returns 0 if no, 1 if check, 2 if checkmate
{
	return 0;
}