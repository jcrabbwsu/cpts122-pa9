#include "ScoreViewScreen.h"
#include "Button.h"
#include "Game.h"
#include "ScoreSubmitter.h"
#include "Background.h"

#include <sstream>

ScoreViewScreen::ScoreViewScreen() {
}

ScoreViewScreen::~ScoreViewScreen() {
}

void ScoreViewScreen::init() {
	addChildGameObject(new Background());

	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	titleText.setString("High Scores");
	titleText.setFont(font);
	titleText.setFillColor(sf::Color::White);
	titleText.setOrigin(
		titleText.getGlobalBounds().width / 2,
		titleText.getGlobalBounds().height / 2
	);

	scoresText.setString("Couldn't load scores. :(");
	scoresText.setFont(font);
	scoresText.setFillColor(sf::Color::White);
	scoresText.setOrigin(
		scoresText.getGlobalBounds().width / 2,
		scoresText.getGlobalBounds().height / 2
	);

	sf::Vector2u windowSize = getGame()->getWindow()->getSize();
	int x = windowSize.x;
	int y = windowSize.y - (windowSize.y * 0.30);

	button = (new Button(200, 40, x - (x * 0.50), y, "Back"));
	button->setCallback([this]() {
		this->getGame()->transitionToMenu();
	});
	addChildGameObject(button);

	getGame()->getScoreSubmitter()->getScores();
}

void ScoreViewScreen::update(double deltaTime) {
	titleText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		100.0
	);

	scoresText.setPosition(
		getGame()->getWindow()->getSize().x / 2,
		170.0
	);

	sf::Vector2u windowSize = getGame()->getWindow()->getSize();
	int x = windowSize.x;
	int y = windowSize.y - (windowSize.y * 0.30);

	button->setPosition(x - (x * 0.50), y);

	draw(titleText);
	draw(scoresText);
}

bool ScoreViewScreen::isOutOfBounds() {
	return false;
}

sf::FloatRect ScoreViewScreen::getBounds() {
	return sf::FloatRect();
}

void ScoreViewScreen::setScores(std::vector<score_t> scores) {
	this->scores = scores;
	std::ostringstream oss;

	for (auto score : scores) {
		oss << score.initials << "  " << score.score << std::endl;
	}
	scoresText.setString(oss.str().c_str());
}
