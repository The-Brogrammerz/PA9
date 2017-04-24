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
	tex.loadFromFile("chess-piece-texture.png");
	this->setTexture(&tex);

	sf::Vector2u textureSize = tex.getSize();

	this->setTextureRect(sf::IntRect(textureSize.x * 5 / 12, 0, (textureSize.x) / 12 - 10, (textureSize.y)));
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