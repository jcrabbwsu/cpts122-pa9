#pragma once

#include "GameObject.h"

class Level : public GameObject {
	int spawnTimer;
	int spawnCount;

	/**
	 * smaller spawn frequency = faster spawn, larger spawn frequency = slower spawn 
	 */
	int spawnFreq; 

public:
	Level(int newTimer, int newCount, int newFreq);

	void init();
	void update(double deltaTime);

	void spawnNewHostile(int value = 0);
	void updateSpawnCount();
	void updateSpawnFreq();
	const sf::Vector2f &randomVector();
};