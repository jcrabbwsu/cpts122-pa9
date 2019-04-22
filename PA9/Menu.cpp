#include "Menu.h"
#include "Game.h"
#include "Background.h"

//constructor for menu class
Menu::Menu()
{
}

//prints game menu using specific font
void Menu::printMenu()
{
}

//extracts font from file and stores in class
void Menu::init()
{
	addChildGameObject(new Background());

	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	this->menuText = sf::Text();
	this->menuText.setString("Welcome to Asteroids!");
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color::White);
	this->menuText.setOrigin(
		this->menuText.getGlobalBounds().width / 2,
		this->menuText.getGlobalBounds().height / 2
	);
}

void Menu::update(double deltaTime)
{
	this->menuText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		200.0
	);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		getGame()->transitionToGame();
	}

	draw(menuText);
}

sf::FloatRect Menu::getBounds()
{
	return sf::FloatRect();
}

bool Menu::isOutOfBounds()
{
	return false;
}
