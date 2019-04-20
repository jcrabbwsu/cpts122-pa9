#pragma once

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

	void outOfBounds();//delete objects that have exited the window area
	void setOutOfBounds();//detect whether objects have left the bounds of the window
	void spawnNewHostile(int value = 0);
	void updateSpawnCount();
	void updateSpawnFreq();//only operates on asteroid spawn rate
	const sf::Vector2f &randomVector();
	void spawnBullet(int IFF, sf::Vector2f & spawnPoint);
	sf::FloatRect getBounds();
};