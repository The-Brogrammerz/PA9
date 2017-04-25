#pragma once

#include "ChessPieces.hpp"

class Kings : public ChessPieces
{
public:
	Kings(Team newT);
	~Kings();

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Kings::Kings(Team newT)
{
	this->t = newT;
	tex.loadFromFile("White King.png");
	this->setTexture(&tex);
}

Kings::~Kings()
{

}

void Kings::killOpponentPiece()
{

}

bool Kings::move()
{
	return true;
}


bool Kings::checkPath()
{
	return false;
}

int Kings::checkIfCheckmate() // returns 0 if no, 1 if check, 2 if checkmate
{
	return 0;
}