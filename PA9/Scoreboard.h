#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

/// <summary>
/// Scoreboard that will draw score/lives in top left of window.
/// </summary>
class Scoreboard : public GameObject {
	/// <summary>
	/// Current score.
	/// </summary>
	int score = 0;

	/// <summary>
	/// Font for drawing.
	/// </summary>
	sf::Font font;

	/// <summary>
	/// Text for score.
	/// </summary>
	sf::Text scoreText;

	sf::Clock totalTime;

public:
	Scoreboard();
	~Scoreboard();
	virtual void setOutOfBounds();

	/// <summary>
	/// Create Font and Text objects.
	/// </summary>
	void init();

	/// <summary>
	/// Update Text and draw it to the screen.
	/// </summary>
	/// <param name="deltaTime"></param>
	void update(double deltaTime);

	/// <summary>
	/// Get current score.
	/// </summary>
	/// <returns>Current score</returns>
	int getScore();


	/// <summary>
	/// Add given number to the current score.
	/// </summary>
	/// <param name="score">Score to add to current score</param>
	void addToScore(int score);

	sf::FloatRect getBounds();
};
