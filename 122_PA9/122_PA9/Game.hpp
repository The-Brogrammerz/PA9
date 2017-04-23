#include "ChessPieces.hpp"

#define MAX_RECTANGLE_WIDTH 100
#define MAX_RECTANGLE_HEIGHT 100

class Game
{
public:
	Game(float width, float height);
	~Game();

	void drawBoard(sf::RenderWindow &win);

	void drawGame(sf::RenderWindow &win);

	void up();
	void down();

	int getSelectedItem();

private:

	sf::RectangleShape board[8][8];
};

Game::Game(float width, float height)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (r % 2 == 0)
			{
				if (c % 2 == 0)
				{
					board[r][c].setFillColor(sf::Color::Red);
					board[r][c].setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * c, height / 2 - 400 + MAX_RECTANGLE_HEIGHT * r));
					board[r][c].setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
				}
				else
				{
					board[r][c].setFillColor(sf::Color::White);
					board[r][c].setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * c, height / 2 - 400 + MAX_RECTANGLE_HEIGHT * r));
					board[r][c].setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
				}
			}
			else
			{
				if ((c+1) % 2 == 0)
				{
					board[r][c].setFillColor(sf::Color::Red);
					board[r][c].setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * c, height / 2 - 400 + MAX_RECTANGLE_HEIGHT * r));
					board[r][c].setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
				}
				else
				{
					board[r][c].setFillColor(sf::Color::White);
					board[r][c].setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * c, height / 2 - 400 + MAX_RECTANGLE_HEIGHT * r));
					board[r][c].setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
				}
			}
		}
	}
}

Game::~Game()
{

}

void Game::drawBoard(sf::RenderWindow &win)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			win.draw(board[r][c]);
		}
	}
}