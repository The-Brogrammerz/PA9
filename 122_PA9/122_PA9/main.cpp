/****************************************************************************************
*	Creators: Omar Finol-Evans, Zeid (Last Name), Alexis Guzman, Josh McDonald			*
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

	int direction = 1, i = 0, imageWidth = 0, imageHeight = 0, scalar = 0;

	sf::Event evnt;
	sf::Texture t1; // figure image
	sf::Sprite p1[16], p2[16]; // to hold all the player figures 
	//Note: I could of just did one array of 32

	t1.loadFromFile("../figures.png"); // all the pieces from file

	/*for (int k = 0; k < 16; k++) {
		p1[k].setOrigin(5, 30);
		p1[k].setTexture(t1);
		p1[k].setTextureRect(sf::IntRect((300 * i), 0, 300, 400));
		p1[k].setPosition(WIDTH * i, 0);
		p1[k].setScale(1, 1);
		if (i != 6) {
			i++;
		}
	}*/

	// rook
	// by default the origin of the spirte is the topleft corner so did an offset to have the piece
	// be inside the square thats what setOrgin does
	p1[0].setOrigin(5, 30); 
	p1[0].setTexture(t1); // set image to sprite array same thing for the rest
	imageWidth = p1[0].getGlobalBounds().width / 6;
	imageHeight = p1[0].getGlobalBounds().height / 2;
	p1[0].setTextureRect(sf::IntRect(imageWidth * 0, 0, imageWidth, imageHeight)); // isolate the image within the image 
	// that i just want which is rook thats why sprites are effected
	p1[0].setPosition((WIDTH / 8) * 0, 0);
	p1[0].setScale(.25, .25); // rescale image to fit inside square

	/*Note: I used 300 because the image resolution is 1800 x 800 and since there is 
	two rows of 6 images for each row. Then to make things easier and more generic I 
	divide the image width / 6 and image height / 2*/

	//knight
	p1[1].setOrigin(5, 30);
	p1[1].setTexture(t1);
	p1[1].setTextureRect(sf::IntRect(imageWidth * 4, 0, imageWidth, imageHeight));
	p1[1].setPosition((WIDTH / 8) * 1, 0);
	p1[1].setScale(.25, .25);

	// bishop
	p1[2].setOrigin(5, 30);
	p1[2].setTexture(t1);
	p1[2].setTextureRect(sf::IntRect(imageWidth * 1, 0, imageWidth, imageHeight));
	p1[2].setPosition((WIDTH / 8) * 2, 0);
	p1[2].setScale(.25, .25);

	// Queen
	p1[3].setOrigin(5, 30);
	p1[3].setTexture(t1);
	p1[3].setTextureRect(sf::IntRect(imageWidth * 2, 0, imageWidth, imageHeight));
	p1[3].setPosition((WIDTH / 8) * 3, 0);
	p1[3].setScale(.25, .25);

	// king
	p1[4].setOrigin(5, 30);
	p1[4].setTexture(t1);
	p1[4].setTextureRect(sf::IntRect(imageWidth * 3, 0, imageWidth, imageHeight));
	p1[4].setPosition((WIDTH / 8) * 4, 0);
	p1[4].setScale(.25, .25);

	// bishop
	p1[5].setOrigin(5, 30);
	p1[5].setTexture(t1);
	p1[5].setTextureRect(sf::IntRect(imageWidth * 1, 0, imageWidth, imageHeight));
	p1[5].setPosition((WIDTH / 8) * 5, 0);
	p1[5].setScale(.25, .25);

	//knight
	p1[6].setOrigin(5, 30);
	p1[6].setTexture(t1);
	p1[6].setTextureRect(sf::IntRect(imageWidth * 4, 0, imageWidth, imageHeight));
	p1[6].setPosition((WIDTH / 8) * 6, 0);
	p1[6].setScale(.25, .25);

	//Rook
	p1[7].setOrigin(5, 30);
	p1[7].setTexture(t1);
	p1[7].setTextureRect(sf::IntRect(imageWidth * 0, 0, imageWidth, imageHeight));
	p1[7].setPosition((WIDTH / 8) * 7, 0);
	p1[7].setScale(.25, .25);

	// Pawn
	for (i = 8; i < 16; i++) {
		p1[i].setOrigin(5, 30);
		p1[i].setTexture(t1);
		p1[i].setTextureRect(sf::IntRect(imageWidth * 5, 0, imageWidth, imageHeight));
		p1[i].setPosition((WIDTH / 8) * scalar, (HEIGHT / 8));
		p1[i].setScale(.25, .25);
		scalar++;
	}
	
	// rook
	p2[0].setOrigin(5, 30);
	p2[0].setTexture(t1);
	p2[0].setTextureRect(sf::IntRect(imageWidth * 0, imageHeight, imageWidth, imageHeight));
	p2[0].setPosition((WIDTH / 8) * 0, HEIGHT - 81.25);
	p2[0].setScale(.25, .25);

	//knight
	p2[1].setOrigin(5, 30);
	p2[1].setTexture(t1);
	p2[1].setTextureRect(sf::IntRect(imageWidth * 4, imageHeight, imageWidth, imageHeight));
	p2[1].setPosition((WIDTH / 8) * 1, HEIGHT - 81.25);
	p2[1].setScale(.25, .25);

	// bishop
	p2[2].setOrigin(5, 30);
	p2[2].setTexture(t1);
	p2[2].setTextureRect(sf::IntRect(imageWidth * 1, imageHeight, imageWidth, imageHeight));
	p2[2].setPosition((WIDTH / 8) * 2, HEIGHT - 81.25);
	p2[2].setScale(.25, .25);

	// Queen
	p2[3].setOrigin(5, 30);
	p2[3].setTexture(t1);
	p2[3].setTextureRect(sf::IntRect(imageWidth * 2, imageHeight, imageWidth, imageHeight));
	p2[3].setPosition((WIDTH / 8) * 3, HEIGHT - 81.25);
	p2[3].setScale(.25, .25);

	// king
	p2[4].setOrigin(5, 30);
	p2[4].setTexture(t1);
	p2[4].setTextureRect(sf::IntRect(imageWidth * 3, imageHeight, imageWidth, imageHeight));
	p2[4].setPosition((WIDTH / 8) * 4, HEIGHT - 81.25);
	p2[4].setScale(.25, .25);

	// bishop
	p2[5].setOrigin(5, 30);
	p2[5].setTexture(t1);
	p2[5].setTextureRect(sf::IntRect(imageWidth * 1, imageHeight, imageWidth, imageHeight));
	p2[5].setPosition((WIDTH / 8) * 5, HEIGHT - 81.25);
	p2[5].setScale(.25, .25);

	//knight
	p2[6].setOrigin(5, 30);
	p2[6].setTexture(t1);
	p2[6].setTextureRect(sf::IntRect(imageWidth * 4, imageHeight, imageWidth, imageHeight));
	p2[6].setPosition((WIDTH / 8) * 6, HEIGHT - 81.25);
	p2[6].setScale(.25, .25);

	//Rook
	p2[7].setOrigin(5, 30);
	p2[7].setTexture(t1);
	p2[7].setTextureRect(sf::IntRect(imageWidth * 0, imageHeight, imageWidth, imageHeight));
	p2[7].setPosition((WIDTH / 8) * 7, HEIGHT - 81.25);
	p2[7].setScale(.25, .25);

	// Pawn
	scalar = 0;
	for (i = 8; i < 16; i++) 
	{
		p2[i].setOrigin(5, 30);
		p2[i].setTexture(t1);
		p2[i].setTextureRect(sf::IntRect(imageWidth * 5, imageHeight, imageWidth, imageHeight));
		p2[i].setPosition((WIDTH / 8) * scalar, (HEIGHT / 8) * 6);
		p2[i].setScale(.25, .25);
		scalar++;
	}

	while (window.isOpen())
	{
		sf::Event e;

		if (playing) // This will only be executed once the user has selected "Play" on the main menu
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
				}
			}

			window.clear();
			game.drawGame(window); // Draw the game instead
			for (i = 0; i < 16; i++) {
				window.draw(p1[i]);
			}
			for (i = 0; i < 16; i++) {
				window.draw(p2[i]);
			}
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
						else if (menu.getSelectedItem() == 3)
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