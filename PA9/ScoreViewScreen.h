#pragma once

#include "GameObject.h"
#include "ScoreSubmitter.h"

class Button;

class ScoreViewScreen : public GameObject {
	Button *button;
	sf::Font font;
	sf::Text titleText;
	sf::Text scoresText;
	std::vector<score_t> scores;

public:
	ScoreViewScreen();
	~ScoreViewScreen();

	void init();
	void update(double deltaTime);
	bool isOutOfBounds();
	sf::FloatRect getBounds();

	void setScores(std::vector<score_t> scores);
};
