#include "Scoreboard.h"

#include <iostream>
#include <sstream>

Scoreboard::Scoreboard() {
}

Scoreboard::~Scoreboard() {
}

void Scoreboard::setOutOfBounds()
{
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
	scoreString << "Lives: " << 3;

	scoreText.setString(scoreString.str());

	if (totalTime.getElapsedTime().asSeconds() > 1.0) {
		addToScore(1);
		totalTime.restart();
	}

	draw(scoreText);
}

int Scoreboard::getScore() {
	return score;
}

void Scoreboard::addToScore(int score) {
	this->score += score;
}

sf::FloatRect Scoreboard::getBounds() {
	return scoreText.getGlobalBounds();
}
