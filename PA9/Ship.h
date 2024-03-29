#pragma once

#include "GameObject.h"
#include <math.h>

class Ship : public GameObject
{
	float mFacing;
	float mMoveSpeed;
	float x = 0;
	float y = 0;
	sf::Vector2f mBoundary;

	sf::Sprite shipSprite;
	sf::Texture shipTexture;
	sf::Clock shootClock;
	sf::Clock respawnClock;
	sf::CircleShape* playerShield;
	sf::Color* shieldColor;

public:
	Ship();
	~Ship();

	void moveForward(double deltaTime);
	void turnLeft();
	void turnRight();
	void fire();

	void init();
	void update(double deltaTime);
	bool isOutOfBounds();
	sf::FloatRect getBounds();
	sf::Clock getRespawnClock();
	sf::Sprite getShipSprite();
};