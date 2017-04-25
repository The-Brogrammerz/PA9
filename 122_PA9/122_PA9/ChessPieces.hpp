#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class ChessPieces : public sf::RectangleShape // Base Class for All of the Chess Pieces
{
public:
	virtual void killOpponentPiece() = 0;

	virtual bool move() = 0;

	virtual bool checkPath() = 0;

	virtual int checkIfCheckmate() = 0; // returns 0 if no, 1 if check, 2 if checkmate

	int getX();
	void setX(int newX);

	int getY();
	void setY(int newY);

protected:
	int x; // Position on row of chess board
	int y; // Position on column of chess boar

	char type;

	sf::Texture tex;
};

int ChessPieces::getX()
{
	return x;
}
void ChessPieces::setX(int newX)
{
	x = newX;
}

int ChessPieces::getY()
{
	return y;
}
void ChessPieces::setY(int newY)
{
	y = newY;
}
