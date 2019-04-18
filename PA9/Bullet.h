#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Enemies.h"

class Bullet : public Enemies
{
	sf::Vector2f mMoveVector;
	sf::Vector2f mSpawnPoint;
	int mSpawnWall;
	sf::CircleShape circleShape;
	double offset = 0;
	bool mIFF;//-----------------true = player bullet, false = enemy bullet, controls what the bullet will collide with
	int randomSigned();

public:
	Bullet(bool IFF, sf::Vector2f spawnPoint, double offset = 0);//---NOTE: requires different arguments from init of other enemy classes
	~Bullet();

	void init();
	void update(double deltaTime);
	void setOutOfBounds();
	void setMoveVector();
	void setSpawnPoint();
	bool getIFF();
};