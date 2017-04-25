#pragma once

#include "ChessPieces.hpp"

class Rookes : public ChessPieces
{
public:
	Rookes(Team newT);
	~Rookes();

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Rookes::Rookes(Team newT)
{
	this->t = newT;
	tex.loadFromFile("White Rook.png");
	this->setTexture(&tex);
}

Rookes::~Rookes()
{

}

void Rookes::killOpponentPiece()
{

}

bool Rookes::move()
{
	return true;
}


bool Rookes::checkPath()
{
	return false;
}

int Rookes::checkIfCheckmate() // returns 0 if no, 1 if check, 2 if checkmate
{
	return 0;
}