#include <SFML\Graphics.hpp>
#include <iostream>
#include "ChessPieces.hpp"

class ChessBoard : public sf::RectangleShape
{
public:
	ChessBoard();
	ChessBoard(const sf::Color &color, const sf::Vector2f &position, const sf::Vector2f &size);
	~ChessBoard();

	bool getIsOccupied();
	void setIsOccupied(bool &s);

	void setChessPiece(ChessPieces *piece);
protected:
	bool spaceIsOccupied;

	ChessPieces *piece;
};

ChessBoard::ChessBoard()
{

}

ChessBoard::ChessBoard(const sf::Color &color, const sf::Vector2f &position, const sf::Vector2f &size)
{
	this->setFillColor(color);
	this->setPosition(position);
	this->setSize(size);

	spaceIsOccupied = false;
}

ChessBoard::~ChessBoard()
{

}

bool ChessBoard::getIsOccupied()
{
	return spaceIsOccupied;
}

void ChessBoard::setIsOccupied(bool &s)
{
	spaceIsOccupied = s;
}
