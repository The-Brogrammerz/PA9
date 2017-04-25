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

	bool checkIfPieceInSpot(sf::Vector2i &f, Team team);

	bool tryMovePiece(sf::Vector2i &start, sf::Vector2i &end, Team team);

	void shiftArrayPositions(ChessPieces *arr[], int startIndex, int length);

private:
	ChessBoard board[8][8];

	ChessPieces *blackTeam[16];
	ChessPieces *whiteTeam[16];

	sf::Text escapeText;
	sf::Font font;

	int totalTurns;

	int numBlackPieces;
	int numWhitePieces;
};

Game::Game(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	bool value = true;
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

			if (r == 0 || r == 1 || r == 6 || r == 7)
			{
				value = true;
				board[r][c].setIsOccupied(value);
			}
			else
			{
				value = false;
				board[r][c].setIsOccupied(value);
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

			blackTeam[i]->setX((i-8));
			blackTeam[i]->setY(0);
			blackTeam[i]->setFillColor(sf::Color::Black);

			blackTeam[i]->setSize(sf::Vector2f(WIDTH, HEIGHT));
			blackTeam[i]->setPosition(sf::Vector2f(width / 2 - 325 + WIDTH * (i - 8), height / 2 - 325 + HEIGHT * 0));
		}

		blackTeam[i]->setIndex(i);

		board[blackTeam[i]->getY()][blackTeam[i]->getX()].setChessPiece(blackTeam[i]);
	}

	for (int i = 0; i < 16; i++) //This for loop sets up the white team on the bottom side of the chess board
	{
		if (i < 8)
		{
			whiteTeam[i] = new Pawns(WHITE);
			whiteTeam[i]->setSize(sf::Vector2f(WIDTH, HEIGHT));
			whiteTeam[i]->setPosition(sf::Vector2f(width / 2 - 325 + WIDTH * i, height / 2 - 325 + HEIGHT * 6));
			whiteTeam[i]->setX(i);
			whiteTeam[i]->setY(6);
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

			whiteTeam[i]->setX((i - 8));
			whiteTeam[i]->setY(7);

			whiteTeam[i]->setSize(sf::Vector2f(WIDTH, HEIGHT));
			whiteTeam[i]->setPosition(sf::Vector2f(width / 2 - 325 + WIDTH * (i - 8), height / 2 - 325 + HEIGHT * 7));
		}
		whiteTeam[i]->setIndex(i);

		board[whiteTeam[i]->getY()][whiteTeam[i]->getX()].setChessPiece(whiteTeam[i]);
	}

	escapeText.setFont(font);
	escapeText.setString("Press \'ESC\' to exit out of game.");
	escapeText.setColor(sf::Color::White);
	escapeText.setOrigin(sf::Vector2f(0, 0));
	escapeText.setPosition(sf::Vector2f(0, 0));
	escapeText.setCharacterSize(16);

	totalTurns = 0;

	numBlackPieces = 16;
	numWhitePieces = 16;
}

Game::~Game()
{
	for (int i = 0; i < 16; i++)
	{
		if (numBlackPieces > i)
			delete blackTeam[i];

		if (numWhitePieces > i)
			delete whiteTeam[i];
	}
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

	for (int c = 0; c < 16; c++)
	{
		if(numBlackPieces > c)
			win.draw(*blackTeam[c]); // Draws the black and white pieces to the screen
	
		if (numWhitePieces > c)
			win.draw(*whiteTeam[c]);
	}


	win.draw(escapeText);

}

bool Game::checkIfPieceInSpot(sf::Vector2i &f, Team team)
{
	int x = 0, y = 0;

	x = f.x / 81.25;
	y = f.y / 81.25;

	if (board[y][x].getIsOccupied() == true && board[y][x].getChessPiece()->getTeam() == team)
		return true;
	else
		return false;
}

bool Game::tryMovePiece(sf::Vector2i &start, sf::Vector2i &end, Team team)
{
	bool value = false;

	int deletedIndex = 0;

	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	x1 = start.x / 81.25;
	y1 = start.y / 81.25;
	x2 = end.x / 81.25;
	y2 = end.y / 81.25;

	if (x1 == x1 && y1 == y2)
		return false;

	if (board[y1][x1].getChessPiece()->getType() == 'K')
	{
		/*if (x1 == x1 || y1 == y2)
		{
			if (board[y2][x2].getIsOccupied())
			{
				if (board[y2][x2].getChessPiece()->getTeam() != team)
				{
					board[y2][x2].killChessPiece();
				}
				else
					return false;
			}
			else
			{
				board[y1][x1].getChessPiece()->move(end);

				board[y2][x2].setChessPiece(board[y1][x1].getChessPiece());

				board[y1][x1].getChessPiece() = nullptr;
				
				return true;
			}
		}*/
	}
	if (board[y1][x1].getChessPiece()->getType() == 'P' && team == WHITE)
	{	
		if (y1 > y2 && y2 > y1 - 2)
		{
			if (x1 == x2)
			{
				if (board[y2][x2].getIsOccupied())
				{
					return false;
				}
				else
				{
					board[y1][x1].getChessPiece()->move(end);

					board[y2][x2].setChessPiece(board[y1][x1].getChessPiece());

					board[y2][x2].getChessPiece()->setPosition(board[y2][x2].getPosition());

					board[y1][x1].getChessPiece() = nullptr;

					value = true;
					board[y2][x2].setIsOccupied(value);

					value = false;
					board[y1][x1].setIsOccupied(value);

					return true;
				}
			}
			else if (x1 + 1 == x2 || x1 - 1 == x2)
			{
				if (board[y2][x2].getIsOccupied())
				{
					if (board[y2][x2].getChessPiece()->getTeam() != team)
					{
						deletedIndex = board[y2][x2].getChessPiece()->getIndex();
						board[y2][x2].killChessPiece();

						shiftArrayPositions(blackTeam, deletedIndex, numBlackPieces);
						numBlackPieces--;

						board[y2][x2].getChessPiece() = new Pawns(team);

						board[y1][x1].getChessPiece()->move(end);

						board[y2][x2].setChessPiece(board[y1][x1].getChessPiece());

						board[y2][x2].getChessPiece()->setPosition(board[y2][x2].getPosition());

						board[y1][x1].getChessPiece() = nullptr;

						value = true;
						board[y2][x2].setIsOccupied(value);

						value = false;
						board[y1][x1].setIsOccupied(value);

						return true;
					}
					else
						return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
			return false;
	}
	if (board[y1][x1].getChessPiece()->getType() == 'P' && team == BLACK)
	{
		if (y1 < y2 && y2 < y1 + 2)
		{
			if (x1 == x2)
			{
				if (board[y2][x2].getIsOccupied())
				{
					return false;
				}
				else
				{
					board[y1][x1].getChessPiece()->move(end);

					board[y2][x2].setChessPiece(board[y1][x1].getChessPiece());

					board[y2][x2].getChessPiece()->setPosition(board[y2][x2].getPosition());

					board[y1][x1].getChessPiece() = nullptr;

					value = true;
					board[y2][x2].setIsOccupied(value);

					value = false;
					board[y1][x1].setIsOccupied(value);

					return true;
				}
			}
			else if (x1 + 1 == x2 || x1 - 1 == x2)
			{
				if (board[y2][x2].getIsOccupied())
				{
					if (board[y2][x2].getChessPiece()->getTeam() != team)
					{
						deletedIndex = board[y2][x2].getChessPiece()->getIndex();
						board[y2][x2].killChessPiece();

						shiftArrayPositions(whiteTeam, deletedIndex, numWhitePieces);
						numWhitePieces--;

						board[y2][x2].getChessPiece() = new Pawns(team);

						board[y1][x1].getChessPiece()->move(end);

						board[y2][x2].setChessPiece(board[y1][x1].getChessPiece());

						board[y2][x2].getChessPiece()->setPosition(board[y2][x2].getPosition());

						board[y1][x1].getChessPiece() = nullptr;

						value = true;
						board[y2][x2].setIsOccupied(value);

						value = false;
						board[y1][x1].setIsOccupied(value);

						return true;
					}
					else
						return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
			return false;
	}

	return false;
}

void Game::shiftArrayPositions(ChessPieces *arr[], int startIndex, int length)
{
	ChessPieces *pNext = arr[startIndex+1];

	for (int i = startIndex + 1; i < length; i++)
	{
		if (i == length - 1)
		{
			arr[i] = nullptr;
		}
		else
		{
			arr[i]->setIndex(i-1);
			arr[i - 1] = arr[i];
		}
	}
}