#pragma once

#include "GameObject.h"

class Enemies : public GameObject
{
public:
	Enemies(float moveSpeed, sf::Vector2f &spawnPoint, sf::Color &color);
	Enemies();
	~Enemies();

	void setSize();
	void init();
	void update(double deltaTime);

public:
	float mMoveVector;
	sf::Vector2f mSpawnPoint;
	float mMoveSpeed;
	sf::Color mColor;
	float mSize;

	sf::Vector2f mCollisionType;

	sf::CircleShape enemyShape;
};