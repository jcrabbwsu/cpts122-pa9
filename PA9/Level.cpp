#include "Level.h"
#include "Circle.h"

Level::Level(int newTimer, int newCount, int newFreq)
		: scoreboard(new Scoreboard()) {
	spawnTimer = newTimer;
	spawnCount = newCount;
	spawnFreq = newFreq;
}

void Level::init() {
	addChildGameObject(scoreboard);
}

void Level::update(double deltaTime) {
	if (spawnTimer % spawnFreq == 0) {
		spawnNewHostile();
	}
	spawnTimer++;

	if (spawnTimer % 50 == 0 && spawnFreq > 1) {
		updateSpawnFreq();
	}
}

void Level::spawnNewHostile(int value) {
	addChildGameObject(new Circle(value));
}

void Level::updateSpawnCount() {
	spawnCount += 1;
}

void Level::updateSpawnFreq() {
	spawnFreq -= 1;
}

const sf::Vector2f & Level::randomVector() {
	return sf::Vector2f(1, 1);
}
