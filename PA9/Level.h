#pragma once

#include "GameObject.h"
#include "Scoreboard.h"

class Level : public GameObject {
	int spawnTimer;
	int spawnCount;

	/// <summary>
	/// smaller spawn frequency = faster spawn, larger spawn frequency = slower spawn 
	/// </summary>
	int spawnFreq; 

	/// <summary>
	/// Pointer to the Scoreboard.
	/// </summary>
	Scoreboard *scoreboard;

public:
	Level(int newTimer, int newCount, int newFreq);

	/// <summary>
	/// Create the Scoreboard.
	/// TODO: Add player, other entities which will only
	/// spawn once.
	/// </summary>
	void init();

	/// <summary>
	/// Spawn new hostiles, etc. Update scoreboard.
	/// </summary>
	/// <param name="deltaTime">Time between frames</param>
	void update(double deltaTime);

	void spawnNewHostile(int value = 0);
	void updateSpawnCount();
	void updateSpawnFreq();
	const sf::Vector2f &randomVector();
};