#pragma once

#include "GameObject.h"

class Circle : public GameObject {
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
	void setMoveVector();
	void setSpawnPoint();
	void setSpawnWall();
};
