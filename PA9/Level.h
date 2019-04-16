#pragma once

#include "Game.h"
#include <time.h>

class Level
{
public:
	Level(int newTimer, int newCount, int newFreq);
	void runTheGame();
	void spawnNewHostile(int value = 0);
	void updateSpawnCount();
	void updateSpawnFreq();
	const sf::Vector2f & randomVector();
private:
	Game mTheGame;
	int mSpawnTimer;
	int mSpawnCount;
	int mSpawnFreq;//smaller spawn frequency = faster spawn, larger spawn frequency = slower spawn
};