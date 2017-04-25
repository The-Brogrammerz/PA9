#pragma once

#include "ChessPieces.hpp"

class Bishops : public ChessPieces
{
public:
	Bishops(Team newT);
	~Bishops();

	void killOpponentPiece();

	bool move();

	bool checkPath();

	int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Bishops::Bishops(Team newT) 
{
	this->t = newT;
	tex.loadFromFile("White Bishop.png");
	this->setTexture(&tex);
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