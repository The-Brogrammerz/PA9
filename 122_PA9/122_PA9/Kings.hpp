#pragma once

#include "ChessPieces.hpp"

class Kings : public ChessPieces
{
public:
	Kings();
	~Kings();

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Kings::Kings()
{
	
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