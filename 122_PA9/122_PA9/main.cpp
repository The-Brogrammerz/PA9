/****************************************************************************************
*	Creators: Omar Finol-Evans, Zeid Al-Ameedi, Alexis Guzman, Josh McDonald			*
*	Class: CptS 122, Spring 2017														*
*	Programming Assignment: Project Assignment #9										*
*	Date Due: 4/26/2017																	*
*	Description: Chess																	*
*																						*
*****************************************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"

#define WIDTH 650
#define HEIGHT 650

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chess"); // The entire program will run on this single window

	Menu menu(WIDTH, HEIGHT); // Interface for the Menu
	Game game(WIDTH, HEIGHT); // Interface for the game after the user clicks Play on the Main Menu

	bool p1IsPressed = false;
	bool p2IsPressed = false;
	bool enterIsPressed = false;

	bool playing = false;
	bool occupiedBox = false;

	bool moveSuccessful = false;
	bool turnSuccess = false;

	int direction = 1, i = 0, imageWidth = 0, imageHeight = 0, scalar = 0;
	sf::Vector2i startCoords, endCords;
	
	int totalTurns = 0;
	
	while (window.isOpen())
	{
		sf::Event e;

		if (playing) // This will only be executed once the user has selected "Play" on the main menu
		{
			if (!turnSuccess)
			{
				while (window.pollEvent(e)) // While loop is used to detect when an event has occured, an event being an interaction between the user and the game
				{
					switch (e.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyPressed:
						if (e.key.code == sf::Keyboard::Escape)
							playing = false;
						break;
					case sf::Event::MouseButtonPressed:
						if (totalTurns % 2 == 0)
						{
							if (!occupiedBox && !moveSuccessful)
							{
								cout << "Select Piece: " << endl;

								startCoords = sf::Mouse::getPosition(window);

								occupiedBox = game.checkIfPieceInSpot(startCoords, WHITE);
							}
							else if (occupiedBox && !turnSuccess)
							{
								endCords = sf::Mouse::getPosition(window);

								turnSuccess = game.tryMovePiece(startCoords, endCords, WHITE);

								if (turnSuccess == true)
								{
									totalTurns++;
									cout << "Valid Move: " << endl;
									turnSuccess = false;
								}
								else
									cout << "Invalid Move: " << endl;

								occupiedBox = false;
							}
						}
						else
						{
							if (!occupiedBox && !moveSuccessful)
							{
								cout << "Select Piece: " << endl;

								startCoords = sf::Mouse::getPosition(window);

								occupiedBox = game.checkIfPieceInSpot(startCoords, BLACK);
							}
							else if (occupiedBox && !turnSuccess)
							{
								endCords = sf::Mouse::getPosition(window);

								turnSuccess = game.tryMovePiece(startCoords, endCords, BLACK);

								if (turnSuccess == true)
								{
									totalTurns++;
									cout << "Valid Move: " << endl;
									turnSuccess = false;
								}
								else
									cout << "Invalid Move: " << endl;

								occupiedBox = false;
							}
						}

						break;
					}

				}
			}

			window.clear();
			game.drawGame(window); // Draw the game instead
		}
		else // If user selects "Play" option, playing will be set to true, and therefore, the main menu will stop being drawn to the window screen
		{
			while (window.pollEvent(e)) // While loop is used to detect when an event has occured, an event being an interaction between the user and the game
			{
				switch (e.type)
				{
				case sf::Event::Closed: // If user clicks close, close the window.
					window.close();
					break;

				case sf::Event::KeyPressed:
					if (!p1IsPressed && e.key.code == sf::Keyboard::Up) //If user presses up key
					{
						menu.up(); // Changes the menu to highlight the option above currently selected option
						p1IsPressed = true;
					}
					else if (!p2IsPressed && e.key.code == sf::Keyboard::Down) //If user presses down key
					{
						menu.down(); // Changes the menu to highlight the option below currently selected option
						p2IsPressed = true;
					}
					else if (!enterIsPressed && e.key.code == sf::Keyboard::Return) //If user presses Enter key
					{
						enterIsPressed = true;
					}

					break;

				case sf::Event::KeyReleased: // When a user releases the key
					if (p1IsPressed && e.key.code == sf::Keyboard::Up)
					{
						p1IsPressed = false;
					}
					else if (p2IsPressed && e.key.code == sf::Keyboard::Down)
					{
						p2IsPressed = false;
					}
					
					else if (enterIsPressed && e.key.code == sf::Keyboard::Return)
					{
						if (menu.getSelectedItem() == 1) // If the first option is selected, the first option being Play, set playing to be true
						{
							playing = true;
						}
						else if (menu.getSelectedItem() == 2)
						{
							exit(EXIT_SUCCESS);
						}

						enterIsPressed = false;
					}

					break;
				}
			}

			window.clear();
			menu.drawMenu(window); // Draws the menu
		}
		window.display();
	}

	return 0;
}