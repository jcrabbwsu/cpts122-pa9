#include "Level.h"

Level::Level(int newTimer, int newCount, int newFreq)
{
	mSpawnTimer = newTimer;
	mSpawnCount = newCount;
	mSpawnFreq = newFreq;
	
	srand((unsigned int)time(NULL));
}

void Level::runTheGame()
{
	sf::Clock clock;
	//spawnNewHostile();
	while (mTheGame.window->isOpen())
	{
		if (mSpawnTimer % mSpawnFreq == 0)
		{
			spawnNewHostile();
		}
		mTheGame.input();
		mTheGame.render(clock.restart());
		mSpawnTimer++;

		if (mSpawnTimer % 50 == 0 && mSpawnFreq > 1)
		{
			updateSpawnFreq();
		}
	}
}

void Level::spawnNewHostile(int value)
{
	mTheGame.addGameObject(new Circle(value));
}

void Level::updateSpawnCount()
{
	mSpawnCount += 1;
}

void Level::updateSpawnFreq()
{
	mSpawnFreq -= 1;
}

const sf::Vector2f & Level::randomVector()
{
	return sf::Vector2f(1, 1);
}
