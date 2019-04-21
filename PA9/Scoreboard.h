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

	//player lives remaining
	int lives;

	//default number of starting lives
	const int maxLives = 3;

	/// <summary>
	/// Font for drawing.
	/// </summary>
	sf::Font font;

	/// <summary>
	/// Text for score.
	/// </summary>
	sf::Text scoreText;

	/// <summary>
	/// Score timer 
	/// </summary>
	sf::Clock scoreTimer;

public:
	Scoreboard();
	~Scoreboard();
	virtual bool isOutOfBounds();

	const int getMaxLives() const;

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

	//get current player lives
	int getLives();

	//change number of player lives, use negative value to take away lives, positive value to add lives
	void setLives(int x);

	/// <summary>
	/// Add given number to the current score.
	/// </summary>
	/// <param name="score">Score to add to current score</param>
	void addToScore(int score);

	sf::FloatRect getBounds();
};
