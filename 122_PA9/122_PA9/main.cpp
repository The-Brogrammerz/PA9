/****************************************************************************************
*	Creators: Omar Finol-Evans, Zeid (Last Name), Alexis Guzman, Josh McDonald			*
*	Class: CptS 122, Spring 2017														*
*	Programming Assignment: Project Assignment #9										*
*	Date Due: 4/26/2017																	*
*	Description: Chess																	*
*																						*
*****************************************************************************************/

#include <iostream>
#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(2500, 1500), "Chess");

	bool p1IsPressed = false;
	bool p2IsPressed = false;

	int direction = 1;

	while (window.isOpen())
	{
		sf::Event e;

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();

			if (e.type == sf::Event::KeyPressed)
			{
				if (!p1IsPressed && e.key.code == sf::Keyboard::S)
				{
					p1IsPressed = true;
				}
				if (!p2IsPressed && e.key.code == sf::Keyboard::K)
				{
					p2IsPressed = true;
				}
			}
			if (e.type == sf::Event::KeyReleased)
			{
				if (p1IsPressed && e.key.code == sf::Keyboard::S)
				{
					p1IsPressed = false;
				}
				if (p2IsPressed && e.key.code == sf::Keyboard::K)
				{
					p2IsPressed = false;
				}
			}
		}
	}

	return 0;
}