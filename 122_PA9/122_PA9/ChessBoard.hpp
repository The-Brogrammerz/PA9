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

	void setChessPiece(ChessPieces *&piece);

	ChessPieces *& getChessPiece();

	bool killChessPiece();
protected:
	bool spaceIsOccupied;

	ChessPieces *piece;
	int team; // representation of which teams piece is on the space
	char pieceType;
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
	piece = nullptr;
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

void ChessBoard::setChessPiece(ChessPieces *&piece)
{
	this->piece = piece;
}

ChessPieces *& ChessBoard::getChessPiece() 
{
	return piece;
}

bool ChessBoard::killChessPiece()
{
	delete piece;

	return true;
}