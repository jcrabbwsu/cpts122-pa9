#pragma once

#include "GameObject.h"
#include "Button.h"

class ScoreSubmissionScreen : public GameObject {
	Button *button;
	sf::Font font;
	sf::Text typeInitials;
	sf::Text initialsText;
	int score;
	int charCount = 0;
	char initials[4] = "AAA";

public:
	ScoreSubmissionScreen();
	~ScoreSubmissionScreen();

	void init();
	void update(double deltaTime);

	bool isOutOfBounds();
	sf::FloatRect getBounds();

	void setScore(int score);
	void addChar(char c);
	void setCharCount(int i);
};
