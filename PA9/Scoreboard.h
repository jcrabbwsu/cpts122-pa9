#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

class Scoreboard : public GameObject {
	int score = 0;
	sf::Font font;
	sf::Text scoreText;
	sf::Text livesText;

public:
	Scoreboard();
	~Scoreboard();

	void init();
	void update(double deltaTime);
	int getScore();
	void addToScore(int score);
};
