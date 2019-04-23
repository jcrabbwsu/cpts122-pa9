#include "Menu.h"
#include "Game.h"
#include "Background.h"

//constructor for menu class
Menu::Menu() {
}

Menu::~Menu() {
}

//extracts font from file and stores in class
void Menu::init() {
	addChildGameObject(new Background());

	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	//initialize asteriod title sprite
	titleTexture.loadFromFile("asteroidstitle.png");
	titleSprite.setTexture(titleTexture);
	titleSprite.setScale(0.8, 0.8);
	titleSprite.setOrigin(
		titleSprite.getGlobalBounds().width / 2,
		titleSprite.getGlobalBounds().height / 2
	);

	//initialize rules text
	rulesText.setString("WASD to move\nSpacebar to shoot");
	rulesText.setFont(font);
	rulesText.setFillColor(sf::Color::White);
	rulesText.setOrigin(
		rulesText.getGlobalBounds().width / 2,
		rulesText.getGlobalBounds().height / 2
	);

	//initialize menu buttons
	newGameButton.setSize(sf::Vector2f(250, 40));
	newGameButton.setFillColor(sf::Color::Transparent);
	newGameButton.setOutlineThickness(5);
	newGameButton.setOutlineColor(sf::Color::White);
	newGameButton.setOrigin(
		newGameButton.getGlobalBounds().width / 2,
		newGameButton.getGlobalBounds().height / 2
	);

	scoreboardButton.setSize(sf::Vector2f(330, 40));
	scoreboardButton.setFillColor(sf::Color::Transparent);
	scoreboardButton.setOutlineThickness(5);
	scoreboardButton.setOutlineColor(sf::Color::White);
	scoreboardButton.setOrigin(
		scoreboardButton.getGlobalBounds().width / 2,
		scoreboardButton.getGlobalBounds().height / 2
	);

	exitButton.setSize(sf::Vector2f(200, 40));
	exitButton.setFillColor(sf::Color::Transparent);
	exitButton.setOutlineThickness(5);
	exitButton.setOutlineColor(sf::Color::White);
	exitButton.setOrigin(
		exitButton.getGlobalBounds().width / 2,
		exitButton.getGlobalBounds().height / 2
	);

	//initialize menu button text
	newGameButtonText.setString("New Game");
	newGameButtonText.setFont(font);
	newGameButtonText.setFillColor(sf::Color::White);
	newGameButtonText.setOrigin(
		newGameButtonText.getGlobalBounds().width / 2,
		newGameButtonText.getGlobalBounds().height / 2
	);

	scoreboardButtonText.setString("Scoreboard");
	scoreboardButtonText.setFont(font);
	scoreboardButtonText.setFillColor(sf::Color::White);
	scoreboardButtonText.setOrigin(
		scoreboardButtonText.getGlobalBounds().width / 2,
		scoreboardButtonText.getGlobalBounds().height / 2
	);

	exitButtonText.setString("Exit");
	exitButtonText.setFont(font);
	exitButtonText.setFillColor(sf::Color::White);
	exitButtonText.setOrigin(
		exitButtonText.getGlobalBounds().width / 2,
		exitButtonText.getGlobalBounds().height / 2
	);
}

void Menu::update(double deltaTime)
{
	//display menu sprite
	titleSprite.setPosition(
		getGame()->getWindow()->getSize().x / 2 - 80,
		250.0
	);

	//display rules text
	rulesText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		550.0
	);

	//display menu buttons
	newGameButton.setPosition(
		getGame()->getWindow()->getSize().x - getGame()->getWindow()->getSize().x + 160,
		650.0
	);
	scoreboardButton.setPosition(
		getGame()->getWindow()->getSize().x / 2 + 10,
		650.0
	);
	exitButton.setPosition(
		getGame()->getWindow()->getSize().x - 130,
		650.0
	);

	//display button text
	newGameButtonText.setPosition(
		getGame()->getWindow()->getSize().x - getGame()->getWindow()->getSize().x + 150,
		640.0
	);
	scoreboardButtonText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		640.0
	);
	exitButtonText.setPosition(
		getGame()->getWindow()->getSize().x - 140,
		640.0
	);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		getGame()->transitionToGame();
	}

	//if exit button is clicked
	if (cursor.getPosition().x < exitButton.getGlobalBounds().left && cursor.getPosition().y > exitButton.getGlobalBounds().top) //needs to be more precise
	{
		exitButton.setFillColor(sf::Color(169, 169, 169));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			getGame()->getWindow()->close();
		}
	}
	else
	{
		exitButton.setFillColor(sf::Color::Transparent);
	}

	draw(titleSprite);
	draw(rulesText);
	draw(newGameButton);
	draw(scoreboardButton);
	draw(exitButton);
	draw(newGameButtonText);
	draw(scoreboardButtonText);
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
