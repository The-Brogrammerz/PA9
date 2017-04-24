#pragma once

#include "ChessPieces.hpp"
#include "ChessBoard.hpp"
#include "Kings.hpp"
#include "Queens.hpp"
#include "Bishops.hpp"
#include "Horses.hpp"
#include "Rookes.hpp"
#include "Pawns.hpp"

#define MAX_RECTANGLE_WIDTH 100
#define MAX_RECTANGLE_HEIGHT 100

class Game
{
public:
	Game(float width, float height);
	~Game();

	void drawBoard(sf::RenderWindow &win);

	void drawGame(sf::RenderWindow &win);

private:
	ChessBoard board[8][8];

	ChessPieces* blackTeam[16];
	ChessPieces* whiteTeam[16];

	sf::Text escapeText;

	int totalTurns;
};

Game::Game(float width, float height)
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	escapeText.setFont(font);
	escapeText.setColor(sf::Color::White);
	escapeText.setPosition(sf::Vector2f(width*0.30, height*0.01));
	escapeText.setString("Press \'ESC\' to go to Main Menu");
	escapeText.setCharacterSize(80);

	bool value = true;

	for (int r = 0; r < 8; r++) // This creates the chess Board, checkered style. Essential to understand how this works
	{
		for (int c = 0; c < 8; c++)
		{
			if (r % 2 == 0) // This is here so that every other row, the first tile of the row will be red, and in between will be white
			{
				if (c % 2 == 0) // This is here so that every column the tiles will change from red to white to red to white...
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
			else // This is here so that every other row, the first tile of the row will be red, and in between will be white
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

			if (r == 0 || r == 1 || r == 8 || r == 9)
				board[r][c].setIsOccupied(value);
		}
	}

	for (int i = 0; i < 16; i++) //This for loop sets up the black team on the top side of the chess board
	{
		if (i < 8)
		{
			blackTeam[i] = new Pawns;
			blackTeam[i]->setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
			blackTeam[i]->setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * i, height / 2 - 400 + MAX_RECTANGLE_HEIGHT * 1));
			blackTeam[i]->setX(i);
			blackTeam[i]->setY(1);
			blackTeam[i]->setFillColor(sf::Color::Black);
		}
		else
		{
			if (i == 8)
				blackTeam[i] = new Rookes;
			else if (i == 9)
				blackTeam[i] = new Horses;
			else if(i == 10)
				blackTeam[i] = new Bishops;
			else if (i == 11)
			{
				blackTeam[i] = new Queens;
			}
			else if(i == 12)
				blackTeam[i] = new Kings;
			else if(i == 13)
				blackTeam[i] = new Bishops;
			else if(i == 14)
				blackTeam[i] = new Horses;
			else
				blackTeam[i] = new Rookes;

			blackTeam[i]->setX(i);
			blackTeam[i]->setY(0);
			blackTeam[i]->setFillColor(sf::Color::Black);
			
			blackTeam[i]->setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
			blackTeam[i]->setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * (i-8), height / 2 - 400 + MAX_RECTANGLE_HEIGHT * 0));
		}
	}

	for (int i = 0; i < 16; i++) //This for loop sets up the white team on the bottom side of the chess board
	{
		if (i < 8)
		{
			whiteTeam[i] = new Pawns;
			whiteTeam[i]->setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
			whiteTeam[i]->setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * i, height / 2 - 400 + MAX_RECTANGLE_HEIGHT * 6));
			blackTeam[i]->setX(i);
			blackTeam[i]->setY(6);
		}
		else
		{
			if (i == 8)
				whiteTeam[i] = new Rookes;
			else if (i == 9)
				whiteTeam[i] = new Horses;
			else if (i == 10)
				whiteTeam[i] = new Bishops;
			else if (i == 11)
			{
				whiteTeam[i] = new Queens;
			}
			else if (i == 12)
				whiteTeam[i] = new Kings;
			else if (i == 13)
				whiteTeam[i] = new Bishops;
			else if (i == 14)
				whiteTeam[i] = new Horses;
			else
				whiteTeam[i] = new Rookes;

			blackTeam[i]->setX(i);
			blackTeam[i]->setY(7);

			whiteTeam[i]->setSize(sf::Vector2f(MAX_RECTANGLE_WIDTH, MAX_RECTANGLE_HEIGHT));
			whiteTeam[i]->setPosition(sf::Vector2f(width / 2 - 400 + MAX_RECTANGLE_WIDTH * (i - 8), height / 2 - 400 + MAX_RECTANGLE_HEIGHT * 7));
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