#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Enemies.h"

class UFO : public Enemies
{
	sf::Vector2f mMoveVector;
	sf::Vector2f mSpawnPoint;
	int mSpawnWall;
	sf::CircleShape circleShape;
	double offset = 0;
	int shotCounter;
	int randomSigned();

public:
	UFO(double offset = 0);
	~UFO();

	void init();
	void update(double deltaTime);
	void setOutOfBounds();
	void setMoveVector();
	void setSpawnPoint();
	void setSpawnWall();
};