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
void Menu::init() {
	addChildGameObject(new Background());

	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	this->titleTexture.loadFromFile("asteroidstitle.png");
	this->titleSprite.setTexture(titleTexture);
	this->titleSprite.setScale(0.8, 0.8);
	this->titleSprite.setOrigin(
		this->titleSprite.getGlobalBounds().width / 2,
		this->titleSprite.getGlobalBounds().height / 2
	);

	rulesText.setString("WASD to move\nSpacebar to shoot");
	rulesText.setFont(font);
	rulesText.setFillColor(sf::Color::White);
	this->rulesText.setOrigin(
		this->rulesText.getGlobalBounds().width / 2,
		this->rulesText.getGlobalBounds().height / 2
	);
}

void Menu::update(double deltaTime)
{
	this->titleSprite.setPosition(
		getGame()->getWindow()->getSize().x / 2 - 80,
		300.0
	);
	this->rulesText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		600.0
	);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		getGame()->transitionToGame();
	}

	draw(titleSprite);
	draw(rulesText);
}

sf::FloatRect Menu::getBounds()
{
	return sf::FloatRect();
}

bool Menu::isOutOfBounds()
{
	return false;
}
