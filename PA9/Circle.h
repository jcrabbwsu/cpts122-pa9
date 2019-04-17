#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Enemies.h"

class Circle : public Enemies
{
	sf::Vector2f mMoveVector;
	sf::Vector2f mSpawnPoint;
	int mSpawnWall;
	sf::CircleShape circleShape;
	double offset = 0;

	int randomSigned();

public:
	Circle(double offset = 0);
	~Circle();

	void init();
	void update(double deltaTime);
	void setOutOfBounds();
	void setMoveVector();
	void setSpawnPoint();
	void setSpawnWall();
};
