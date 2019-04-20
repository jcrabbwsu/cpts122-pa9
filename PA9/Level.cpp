#include "Level.h"
#include "Asteroid.h"
#include "Enemies.h"
#include "UFO.h"
#include "Bullet.h"
#include "Ship.h"

Level::Level(int newTimer, int newCount, int newFreq)
		: scoreboard(new Scoreboard())
		, playerShip(new Ship()) {
	spawnTimer = newTimer;
	spawnCount = newCount;
	spawnFreqAsteroid = newFreq;
	spawnFreqUFO = 500;
}

void Level::init() {
	addChildGameObject(scoreboard);
	addChildGameObject(playerShip);
}

void Level::update(double deltaTime) {
	if (spawnTimer % spawnFreqAsteroid == 0) {
		spawnNewHostile(1);//spawn an asteroid based on spawnFreqAsteroid
	}
	if (spawnTimer % spawnFreqUFO == 0)
	{
		spawnNewHostile(2);//spawn a UFO based on UFO spawnFreqUFO
	}

	spawnTimer++;

	//increase spawn rate of enemies over time
	if (spawnTimer % 50 == 0 && spawnFreqAsteroid > 1) {
		updateSpawnFreq();
	}

	outOfBounds();//check and mark all enemies that are out of bounds for deletion
}

void Level::outOfBounds()
{

	for (auto child : children)
	{
		child->setOutOfBounds();

		if (child->getOutOfBounds())
		{
			child->dispose();
		}
	}

}

void Level::setOutOfBounds()
{
}

void Level::spawnNewHostile(int value) {

	switch (value)
	{
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

void Level::spawnBullet(int IFF, sf::Vector2f & spawnPoint)
{
	new Bullet(IFF, spawnPoint);
}

sf::FloatRect Level::getBounds() {
	return sf::FloatRect();
}
