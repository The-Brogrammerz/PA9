#pragma once

#include "ChessPieces.hpp"

class Horses : public ChessPieces
{
public:
	Horses();
	~Horses();

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Horses::Horses()
{
	tex.loadFromFile("White Horse.png");
	this->setTexture(&tex);
}

Horses::~Horses()
{

}

void Horses::killOpponentPiece()
{

}

bool Horses::move()
{
	return true;
}


bool Horses::checkPath()
{
	return false;
}

int Horses::checkIfCheckmate() // returns 0 if no, 1 if check, 2 if checkmate
{
	return 0;
}