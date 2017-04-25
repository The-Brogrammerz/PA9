#pragma once

#include "ChessPieces.hpp"

class Pawns : public ChessPieces
{
public:
	Pawns();
	~Pawns();

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Pawns::Pawns()
{
	
}

Pawns::~Pawns()
{

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