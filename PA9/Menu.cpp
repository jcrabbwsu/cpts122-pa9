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
	titleSprite.setScale(0.7, 0.7);
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

	sf::Vector2u windowSize = getGame()->getWindow()->getSize();
	int x = windowSize.x;
	int y = windowSize.y - (windowSize.y * 0.10);

	playButton = (new Button(200, 40, x - (x * 0.75), y, "Play"));
	scoresButton = (new Button(200, 40, x - (x * 0.50), y, "Highscores"));
	exitButton = (new Button(200, 40, x - (x * 0.25), y, "Exit"));

	playButton->setCallback([this]() {
		this->getGame()->transitionToGame();
	});

	scoresButton->setCallback([this]() {
		this->getGame()->transitiontoScoreView();
	});

	exitButton->setCallback([this]() {
		this->getGame()->getWindow()->close();
	});

	addChildGameObject(playButton);
	addChildGameObject(scoresButton);
	addChildGameObject(exitButton);
}

void Menu::update(double deltaTime)
{
	titleSprite.setPosition(
		getGame()->getWindow()->getSize().x / 2 - 80,
		190.0
	);

	rulesText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		500.0
	);

	sf::Vector2u windowSize = getGame()->getWindow()->getSize();
	int x = windowSize.x;
	int y = windowSize.y - (windowSize.y * 0.10);

	playButton->setPosition(x - (x * 0.75), y);
	scoresButton->setPosition(x - (x * 0.50), y);
	exitButton->setPosition(x - (x * 0.25), y);

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
