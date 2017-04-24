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
	tex.loadFromFile("chess-piece-texture.png");
	this->setTexture(&tex);

	sf::Vector2u textureSize = tex.getSize();

	this->setTextureRect(sf::IntRect(textureSize.x/4 - 10, textureSize.y / 5 - 10, (textureSize.x) / 12 - 10, (textureSize.y*4/5) - 10));
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