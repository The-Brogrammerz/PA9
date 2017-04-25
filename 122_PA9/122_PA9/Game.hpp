#include "ChessPieces.hpp"
#include "ChessBoard.hpp"

#define WIDTH 40
#define HEIGHT 40

class Game
{
public:
	Game(float width, float height);
	~Game();

	void drawBoard(sf::RenderWindow &win);

	void drawGame(sf::RenderWindow &win);

private:
	ChessBoard board[8][8];

	ChessPieces *blackTeam[16];
	ChessPieces *whiteTeam[16];
};

Game::Game(float width, float height)
{
	for (int r = 0; r < 8; r++) // This creates the chess Board, checkered style. Essential to understand how this works
	{
		for (int c = 0; c < 8; c++)
		{
			if (r % 2 == 0) // This is here so that every other row, the first tile of the row will be red, and in between will be white
			{
				if (c % 2 == 0) // This is here so that every column the tiles will change from red to white to red to white...
				{
					board[r][c].setFillColor(sf::Color(255, 193, 122));
					board[r][c].setPosition(sf::Vector2f(width / 8 * c, width / 8 * r));
					board[r][c].setSize(sf::Vector2f(width / 8, width / 8));
				}
				else
				{
					board[r][c].setFillColor(sf::Color(112, 84, 53));
					board[r][c].setPosition(sf::Vector2f(width / 8 * c, width / 8 * r));
					board[r][c].setSize(sf::Vector2f(width / 8, width / 8));
				}
			}
			else // This is here so that every other row, the first tile of the row will be red, and in between will be white
			{
				if ((c+1) % 2 == 0)
				{
					board[r][c].setFillColor(sf::Color(255, 193, 122));
					board[r][c].setPosition(sf::Vector2f(width / 8 * c, width / 8 * r));
					board[r][c].setSize(sf::Vector2f(width / 8, width / 8));
				}
				else
				{
					board[r][c].setFillColor(sf::Color(112, 84, 53));
					board[r][c].setPosition(sf::Vector2f(width / 8 * c, width / 8 * r));
					board[r][c].setSize(sf::Vector2f(width / 8, width / 8));
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
			win.draw(board[r][c]); // Draws the entire board to the screen
		}
	}
}

void Game::drawGame(sf::RenderWindow &win)
{
	drawBoard(win); //Must be executed before anything else so that everything else is drawn ABOVE the board
}