#pragma once

#include "ChessPieces.hpp"

class Pawns : public ChessPieces
{
public:
	Pawns(Team newT);
	~Pawns();

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate

	 int getNumMoves() const;
private:
	int numMoves;
};

Pawns::Pawns(Team newT)
{
	this->t = newT;
	this->numMoves = 0;
	tex.loadFromFile("White Pawn.png");
	this->setTexture(&tex);
}

Pawns::~Pawns()
{
	this->numMoves = 0;
}

int Pawns::getNumMoves() const
{
	return this->numMoves;
}
void Pawns::killOpponentPiece()
{

}

bool Pawns::move()
{
	return true;
}


bool Pawns::checkPath()
{
	return false;
}

int Pawns::checkIfCheckmate() // returns 0 if no, 1 if check, 2 if checkmate
{
	return 0;
}