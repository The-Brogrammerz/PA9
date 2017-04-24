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
	tex.loadFromFile("chess-piece-texture.png");
	this->setTexture(&tex);

	sf::Vector2u textureSize = tex.getSize();

	this->setTextureRect(sf::IntRect(textureSize.x / 12 - 10, textureSize.y / 2 - 20, ((textureSize.x) / 6 - 10) / 2, textureSize.y / 2));
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