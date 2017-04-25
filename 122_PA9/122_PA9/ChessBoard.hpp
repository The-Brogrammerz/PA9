#include <SFML\Graphics.hpp>
#include <iostream>

class ChessBoard : public sf::RectangleShape
{
public:
	ChessBoard();
	ChessBoard(const sf::Color &color, const sf::Vector2f &position, const sf::Vector2f &size);
	~ChessBoard();

	bool getIsOccupied();
	void setIsOccupied(bool &s);
protected:
	bool spaceIsOccupied;
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