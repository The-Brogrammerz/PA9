#pragma once

#include "ChessPieces.hpp"

class Rookes : public ChessPieces
{
public:
	Rookes();
	~Rookes();

	 void killOpponentPiece();

	 bool move();

	 bool checkPath();

	 int checkIfCheckmate(); // returns 0 if no, 1 if check, 2 if checkmate
private:

};

Rookes::Rookes()
{
	tex.loadFromFile("chess-piece-texture.png");
	this->setTexture(&tex);

	sf::Vector2u textureSize = tex.getSize();

	this->setTextureRect(sf::IntRect(textureSize.x / 6 - 10, textureSize.y / 2 - 20, (textureSize.x) / 12 - 10, textureSize.y / 2));
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