#pragma once

#include "GameObject.h"

class Ship : public GameObject
{
public:
	Ship(sf::Vector2f &size, sf::Color color, sf::Vector2f &spawnPoint, float rotationAngle);
	~Ship();

	void moveForward();
	void turnLeft();
	void turnRight();
	void fire();

	void init();
	void update(double deltaTime);

private:
	sf::Vector2f mSize;
	sf::Color mColor;
	sf::Vector2f mPosition;
	float mFacing;
	float mMoveSpeed;

	sf::RectangleShape shipShape;
};