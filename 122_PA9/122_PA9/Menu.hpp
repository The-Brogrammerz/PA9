#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void drawMenu(sf::RenderWindow &win);
	
	void up();
	void down();

	int getSelectedItem();

private:
	int itemSelected;
	sf::Text options[4];
	sf::Font font;
};

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	options[0].setColor(sf::Color::Cyan);
	options[0].setPosition(sf::Vector2f(width*.48, height*.05));
	options[0].setString("Chess");
	options[0].setFont(font);
	options[0].setCharacterSize(80);

	options[1].setColor(sf::Color::Red);
	options[1].setPosition(sf::Vector2f(width/2, height/4));
	options[1].setString("Play");
	options[1].setFont(font);
	options[1].setCharacterSize(52);


	options[2].setColor(sf::Color::White);
	options[2].setPosition(sf::Vector2f(width / 2, height / 4 * 2));
	options[2].setString("Rules");
	options[2].setCharacterSize(52);
	options[2].setFont(font);

	options[3].setColor(sf::Color::White);
	options[3].setPosition(sf::Vector2f(width / 2, height / 4 * 3));
	options[3].setString("Exit");
	options[3].setCharacterSize(52);
	options[3].setFont(font);

	itemSelected = 1;
}

Menu::~Menu()
{

}

void Menu::drawMenu(sf::RenderWindow &win)
{
	for (int i = 0; i < 4; i++)
		win.draw(options[i]);
}

void Menu::up()
{
	if (itemSelected > 1)
	{
		options[itemSelected].setColor(sf::Color::White);
		itemSelected--;
		options[itemSelected].setColor(sf::Color::Red);
	}
}

void Menu::down()
{
	if (itemSelected < 3)
	{
		options[itemSelected].setColor(sf::Color::White);
		itemSelected++;
		options[itemSelected].setColor(sf::Color::Red);
	}
}

int Menu::getSelectedItem()
{
	return itemSelected;
}