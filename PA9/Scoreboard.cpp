#include "Scoreboard.h"

#include <iostream>
#include <sstream>

Scoreboard::Scoreboard() {
	lives = maxLives;
}

Scoreboard::~Scoreboard() {
}

bool Scoreboard::isOutOfBounds() {
	return false;
}

const int Scoreboard::getMaxLives() const
{
	return maxLives;
}

void Scoreboard::init() {
	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	scoreText = sf::Text();
	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);
}

void Scoreboard::update(double deltaTime) {
	std::ostringstream scoreString;
	scoreString << "Score: " << score << std::endl;
	scoreString << "Lives: " << lives;

	scoreText.setString(scoreString.str());

	if (scoreTimer.getElapsedTime().asSeconds() > 1.0) {
		addToScore(1);
		scoreTimer.restart();
	}

	draw(scoreText);
}

int Scoreboard::getScore() {
	return score;
}

int Scoreboard::getLives()
{
	return lives;
}

void Scoreboard::setLives(int x)
{
	lives = lives + x;
}

void Scoreboard::addToScore(int score) {
	this->score += score;
}

sf::FloatRect Scoreboard::getBounds() {
	return scoreText.getGlobalBounds();
}
