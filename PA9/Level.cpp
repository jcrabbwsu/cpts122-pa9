#include "Level.h"
#include "Asteroid.h"
#include "Entity.h"
#include "UFO.h"
#include "Bullet.h"
#include "Ship.h"
#include "Background.h"

Level::Level(int newTimer, int newCount, int newFreq)
		: scoreboard(new Scoreboard())
		, playerShip(new Ship()) {
	spawnTimer = newTimer;
	spawnCount = newCount;
	spawnFreqAsteroid = newFreq;
	spawnFreqUFO = 500;
}

void Level::init() {
	addChildGameObject(new Background());
	addChildGameObject(scoreboard);
	addChildGameObject(playerShip);
}

void Level::update(double deltaTime) {
	if (spawnTimer % spawnFreqAsteroid == 0) {
		// Spawn an asteroid based on spawnFreqAsteroid
		spawnNewHostile(1);
	}
	if (spawnTimer % spawnFreqUFO == 0) {
		// Spawn a UFO based on UFO spawnFreqUFO
		spawnNewHostile(2);
	}

	spawnTimer++;

	//increase spawn rate of enemies over time
	if (spawnTimer % 200 == 0 && spawnFreqAsteroid > 1) {
		updateSpawnFreq();
	}

	// Check and mark all enemies that are out of bounds for deletion.
	for (auto child : children) {
		if (child->isOutOfBounds()) {
			child->dispose();
		}
	}

	if (gameOver()) {
		getGame()->transitionToScoreSubmit(getGame()->getLevel()->getScoreboard()->getScore());
	}
}

Scoreboard *Level::getScoreboard() {
	return scoreboard;
}

bool Level::isOutOfBounds() {
	return false;
}

bool Level::gameOver() {
	return getScoreboard()->getLives() == 0;
}

void Level::spawnNewHostile(int value) {
	switch (value) {
	case 1://spawn an asteroid if value is 1
		addChildGameObject(new Asteroid());
		break;
	case 2://spawn a UFO if value is 2
		addChildGameObject(new UFO());
		break;
	default://spawn nothing if value is anything else
		break;
	}
}

void Level::updateSpawnCount() {
	spawnCount += 1;
}

void Level::updateSpawnFreq() {
	spawnFreqAsteroid -= 1;
}

const sf::Vector2f & Level::randomVector() {
	return sf::Vector2f(1, 1);
}

sf::FloatRect Level::getBounds() {
	return sf::FloatRect();
}
