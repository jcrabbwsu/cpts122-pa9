#pragma once

#include <iostream>
#include "GameObject.h"
#include "Scoreboard.h"
#include "Ship.h"

class Level : public GameObject {
	int spawnTimer;
	int spawnCount;

	/// <summary>
	/// smaller spawn frequency = faster spawn, larger spawn frequency = slower spawn 
	/// </summary>
	int spawnFreqAsteroid; 
	int spawnFreqUFO;

	/// <summary>
	/// Pointer to the Scoreboard.
	/// </summary>
	Scoreboard *scoreboard;

	/// <summary>
	/// Pointer to the ship.
	/// </summary>
	Ship *playerShip;

public:
	Level(int newTimer, int newCount, int newFreq);

	/// <summary>
	/// Initialize the Level.
	/// </summary>
	void init();

	/// <summary>
	/// Spawn new hostiles, etc. Update scoreboard.
	/// </summary>
	/// <param name="deltaTime">Time between frames</param>
	void update(double deltaTime);

	Scoreboard* getScoreboard();

	bool isOutOfBounds();

	//check if player is out of lives
	bool gameOver();

	void spawnNewHostile(int value = 0);
	void updateSpawnCount();
	void updateSpawnFreq();
	const sf::Vector2f &randomVector();
	sf::FloatRect getBounds();
	void setSpawnRateUFO(int rate);
	void setAsteroidSpawnRate(int rate);
};