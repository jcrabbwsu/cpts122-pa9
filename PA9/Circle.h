#pragma once

#include "GameObject.h"

class Circle : public GameObject
{
	sf::CircleShape circleShape;
	double offset = 0;

public:
	Circle(double offset = 0);
	~Circle();

	void init();
	void update(double deltaTime);
	void setMoveVector();
	void setSpawnPoint();
	void setSpawnWall();
	//void update(double deltaTime, const sf::Vector2f & moveVector);
private:
	sf::Vector2f mMoveVector;
	sf::Vector2f mSpawnPoint;
	int mSpawnWall;
	int randomSigned();
};
