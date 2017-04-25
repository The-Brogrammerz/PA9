#include "ChessPieces.hpp"
#include "ChessBoard.hpp"
#include "Bishops.hpp"
#include "Kings.hpp"
#include "Horses.hpp"
#include "Rookes.hpp"
#include "Pawns.hpp"
#include "Queens.hpp"

#define WIDTH 81.25
#define HEIGHT 81.25

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

	int totalTurns;
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

	for (int i = 0; i < 16; i++) //This for loop sets up the black team on the top side of the chess board
	{
		if (i < 8)
		{
			blackTeam[i] = new Pawns(BLACK);
			blackTeam[i]->setSize(sf::Vector2f(WIDTH, HEIGHT));
			blackTeam[i]->setPosition(sf::Vector2f(width / 2 - 325 + WIDTH * i, height / 2 - 325 + HEIGHT * 1));
			blackTeam[i]->setX(i);
			blackTeam[i]->setY(1);

			blackTeam[i]->setFillColor(sf::Color::Black);
		}
		else
		{
			if (i == 8)
				blackTeam[i] = new Rookes(BLACK);
			else if (i == 9)
				blackTeam[i] = new Horses(BLACK);
			else if (i == 10)
				blackTeam[i] = new Bishops(BLACK);
			else if (i == 11)
			{
				blackTeam[i] = new Queens(BLACK);
			}
			else if (i == 12)
				blackTeam[i] = new Kings(BLACK);
			else if (i == 13)
				blackTeam[i] = new Bishops(BLACK);
			else if (i == 14)
				blackTeam[i] = new Horses(BLACK);
			else
				blackTeam[i] = new Rookes(BLACK);

			blackTeam[i]->setX(i);
			blackTeam[i]->setY(0);
			blackTeam[i]->setFillColor(sf::Color::Black);

			blackTeam[i]->setSize(sf::Vector2f(WIDTH, HEIGHT));
			blackTeam[i]->setPosition(sf::Vector2f(width / 2 - 325 + WIDTH * (i - 8), height / 2 - 325 + HEIGHT * 0));
		}
	}

	for (int i = 0; i < 16; i++) //This for loop sets up the white team on the bottom side of the chess board
	{
		if (i < 8)
		{
			whiteTeam[i] = new Pawns(WHITE);
			whiteTeam[i]->setSize(sf::Vector2f(WIDTH, HEIGHT));
			whiteTeam[i]->setPosition(sf::Vector2f(width / 2 - 325 + WIDTH * i, height / 2 - 325 + HEIGHT * 6));
			blackTeam[i]->setX(i);
			blackTeam[i]->setY(6);
		}
		else
		{
			if (i == 8)
				whiteTeam[i] = new Rookes(WHITE);
			else if (i == 9)
				whiteTeam[i] = new Horses(WHITE);
			else if (i == 10)
				whiteTeam[i] = new Bishops(WHITE);
			else if (i == 11)
			{
				whiteTeam[i] = new Queens(WHITE);
			}
			else if (i == 12)
				whiteTeam[i] = new Kings(WHITE);
			else if (i == 13)
				whiteTeam[i] = new Bishops(WHITE);
			else if (i == 14)
				whiteTeam[i] = new Horses(WHITE);
			else
				whiteTeam[i] = new Rookes(WHITE);

			blackTeam[i]->setX(i);
			blackTeam[i]->setY(7);

			whiteTeam[i]->setSize(sf::Vector2f(WIDTH, HEIGHT));
			whiteTeam[i]->setPosition(sf::Vector2f(width / 2 - 325 + WIDTH * (i - 8), height / 2 - 325 + HEIGHT * 7));
		}
	}

	totalTurns = 0;
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

	/*win.draw(escapeText);*/

	for (int c = 0; c < 16; c++)
	{
		win.draw(*blackTeam[c]); // Draws the black and white pieces to the screen
		win.draw(*whiteTeam[c]);
	}
}