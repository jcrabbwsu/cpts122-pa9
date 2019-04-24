#include "ScoreSubmissionScreen.h"
#include "Game.h"
#include "ScoreSubmitter.h"

ScoreSubmissionScreen::ScoreSubmissionScreen() {
}

ScoreSubmissionScreen::~ScoreSubmissionScreen() {
}

void ScoreSubmissionScreen::init() {
	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	typeInitials.setString("Type initials");
	typeInitials.setFont(font);
	typeInitials.setFillColor(sf::Color::White);
	typeInitials.setOrigin(
		typeInitials.getGlobalBounds().width / 2,
		typeInitials.getGlobalBounds().height / 2
	);

	initialsText.setString(initials);
	initialsText.setFont(font);
	initialsText.setFillColor(sf::Color::White);
	initialsText.setOrigin(
		initialsText.getGlobalBounds().width / 2,
		initialsText.getGlobalBounds().height / 2
	);

	sf::Vector2u windowSize = getGame()->getWindow()->getSize();
	int x = windowSize.x;
	int y = windowSize.y - (windowSize.y * 0.10);

	button = (new Button(200, 40, x - (x * 0.50), y, "Submit"));
	button->setCallback([this]() {
		this->getGame()->getScoreSubmitter()->submitScore(initials, score);
		this->getGame()->transitionToMenu();
	});
	addChildGameObject(button);
}

void ScoreSubmissionScreen::update(double deltaTime) {
	typeInitials.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		500.0
	);

	initialsText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		570.0
	);

	sf::Vector2u windowSize = getGame()->getWindow()->getSize();
	int x = windowSize.x;
	int y = windowSize.y - (windowSize.y * 0.10);

	button->setPosition(x - (x * 0.50), y);

	draw(typeInitials);
	draw(initialsText);
}

bool ScoreSubmissionScreen::isOutOfBounds() {
	return false;
}

sf::FloatRect ScoreSubmissionScreen::getBounds() {
	return sf::FloatRect();
}

void ScoreSubmissionScreen::setScore(int score) {
	this->score = score;
}

void ScoreSubmissionScreen::addChar(char c) {
	if (charCount == 3) {
		charCount = 0;
	}
	initials[charCount] = c;
	initialsText.setString(initials);
	charCount++;
}

void ScoreSubmissionScreen::setCharCount(int i)
{
	charCount = i;
}
