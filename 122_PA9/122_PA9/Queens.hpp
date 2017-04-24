#pragma once

#include "ChessPieces.hpp"


class Queens : public ChessPieces
{
public:
	Queens(void);
	 ~Queens(void);

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Queens::Queens()
{
	tex.loadFromFile("chess-piece-texture.png");
	this->setTexture(&tex);

	sf::Vector2u textureSize = tex.getSize();

	this->setTextureRect(sf::IntRect(textureSize.x*1 / 3, 0, (textureSize.x) / 12 - 10, (textureSize.y)));
}

Queens::~Queens()
{

}

void Queens::killOpponentPiece()
{

}

bool Queens::move()
{
	return true;
}


bool Queens::checkPath()
{
	return false;
}

int Queens::checkIfCheckmate() // returns 0 if no, 1 if check, 2 if checkmate
{
	return 0;
}