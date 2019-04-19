#pragma once

#include "GameObject.h"
#include <math.h>

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
	void setOutOfBounds();

private:
	sf::Vector2f mSize;
	sf::Color mColor;
	sf::Vector2f mPosition;
	float mFacing;
	float mMoveSpeed;
	sf::Vector2f mBoundary;

	sf::RectangleShape shipShape;

	/*=====================
	Notes:
	* Does control input need to be in here? If so should they be in update or the functions themselves?
	* Need information on setOutOfBounds
	* Where do we initialize the ship and other objects?
	* DeltaTime * moving X and Y?
	=====================*/
};