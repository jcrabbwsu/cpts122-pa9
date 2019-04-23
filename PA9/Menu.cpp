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

	//initialize asteriod title sprite
	this->titleTexture.loadFromFile("asteroidstitle.png");
	this->titleSprite.setTexture(titleTexture);
	this->titleSprite.setScale(0.8, 0.8);
	this->titleSprite.setOrigin(
		this->titleSprite.getGlobalBounds().width / 2,
		this->titleSprite.getGlobalBounds().height / 2
	);

	//initialize rules text
	rulesText.setString("WASD to move\nSpacebar to shoot");
	rulesText.setFont(font);
	rulesText.setFillColor(sf::Color::White);
	this->rulesText.setOrigin(
		this->rulesText.getGlobalBounds().width / 2,
		this->rulesText.getGlobalBounds().height / 2
	);

	//initialize menu buttons
	newGameButton.setSize(sf::Vector2f(250, 40));
	newGameButton.setFillColor(sf::Color::Transparent);
	newGameButton.setOutlineThickness(5);
	newGameButton.setOutlineColor(sf::Color::White);
	this->newGameButton.setOrigin(
		this->newGameButton.getGlobalBounds().width / 2,
		this->newGameButton.getGlobalBounds().height / 2
	);

	ScoreboardButton.setSize(sf::Vector2f(330, 40));
	ScoreboardButton.setFillColor(sf::Color::Transparent);
	ScoreboardButton.setOutlineThickness(5);
	ScoreboardButton.setOutlineColor(sf::Color::White);
	this->ScoreboardButton.setOrigin(
		this->ScoreboardButton.getGlobalBounds().width / 2,
		this->ScoreboardButton.getGlobalBounds().height / 2
	);

	exitButton.setSize(sf::Vector2f(200, 40));
	exitButton.setFillColor(sf::Color::Transparent);
	exitButton.setOutlineThickness(5);
	exitButton.setOutlineColor(sf::Color::White);
	this->exitButton.setOrigin(
		this->exitButton.getGlobalBounds().width / 2,
		this->exitButton.getGlobalBounds().height / 2
	);

	//initialize menu button text
	newGameButtonText.setString("New Game");
	newGameButtonText.setFont(font);
	newGameButtonText.setFillColor(sf::Color::White);
	this->newGameButtonText.setOrigin(
		this->newGameButtonText.getGlobalBounds().width / 2,
		this->newGameButtonText.getGlobalBounds().height / 2
	);

	ScoreboardButtonText.setString("Scoreboard");
	ScoreboardButtonText.setFont(font);
	ScoreboardButtonText.setFillColor(sf::Color::White);
	this->ScoreboardButtonText.setOrigin(
		this->ScoreboardButtonText.getGlobalBounds().width / 2,
		this->ScoreboardButtonText.getGlobalBounds().height / 2
	);

	exitButtonText.setString("Exit");
	exitButtonText.setFont(font);
	exitButtonText.setFillColor(sf::Color::White);
	this->exitButtonText.setOrigin(
		this->exitButtonText.getGlobalBounds().width / 2,
		this->exitButtonText.getGlobalBounds().height / 2
	);
}

void Menu::update(double deltaTime)
{
	//display menu sprite
	this->titleSprite.setPosition(
		getGame()->getWindow()->getSize().x / 2 - 80,
		250.0
	);
	//display rules text
	this->rulesText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		550.0
	);
	//display menu buttons
	this->newGameButton.setPosition(
		getGame()->getWindow()->getSize().x - getGame()->getWindow()->getSize().x + 160,
		650.0
	);
	this->ScoreboardButton.setPosition(
		getGame()->getWindow()->getSize().x / 2 + 10,
		650.0
	);
	this->exitButton.setPosition(
		getGame()->getWindow()->getSize().x - 130,
		650.0
	);
	//display button text
	this->newGameButtonText.setPosition(
		getGame()->getWindow()->getSize().x - getGame()->getWindow()->getSize().x + 150,
		640.0
	);
	this->ScoreboardButtonText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		640.0
	);
	this->exitButtonText.setPosition(
		getGame()->getWindow()->getSize().x - 140,
		640.0
	);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		getGame()->transitionToGame();
	}

	draw(titleSprite);
	draw(rulesText);
	draw(newGameButton);
	draw(ScoreboardButton);
	draw(exitButton);
	draw(newGameButtonText);
	draw(ScoreboardButtonText);
	draw(exitButtonText);
}

sf::FloatRect Menu::getBounds()
{
	return sf::FloatRect();
}

bool Menu::isOutOfBounds()
{
	return false;
}
