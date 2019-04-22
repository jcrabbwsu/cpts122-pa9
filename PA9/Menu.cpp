#include "Menu.h"

//constructor for menu class
Menu::Menu()
{

}

//prints game menu using specific font
void Menu::printMenu()
{
	this->menuText.setString("WELCOME TO ASTEROIDS!");
	draw(this->menuText);

	this->menuText.setString("    1) Play Game");
	draw(this->menuText);

	this->menuText.setString("    2) See leaderboard");
	draw(this->menuText);

	this->menuText.setString("    3) Exit");
	draw(this->menuText);
}

//extracts font from file and stores in class
void Menu::init()
{
	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	this->menuText = sf::Text();
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color::White);
}

void Menu::update(double deltaTime)
{

}

sf::FloatRect Menu::getBounds()
{
	return sf::FloatRect();
}

bool Menu::isOutOfBounds()
{
	return false;
}
