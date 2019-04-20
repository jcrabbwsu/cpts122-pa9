#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Entity.h"

/**********************************************************
*  BULLET CLASS
* GameObject -> Entity -> Bullet
* This class is used by UFOs and the player.
* "Friendly" player bullets have mIFF = true, 
* "hostile" UFO bullets have mIFF = false.
* mIFF is checked at collision to determine whether an interaction occurs
* (for example, so the player can't kill themself on their own bullets
* or so UFOs can't destroy asteroids).
**********************************************************/

class Bullet : public Entity
{
	sf::Vector2f mMoveVector;
	sf::Vector2f mSpawnPoint;
	int mSpawnWall;
	sf::CircleShape bulletShape;
	double offset = 0;
	bool mIFF;//-----------------true = player bullet, false = enemy bullet, controls what the bullet will collide with
	int randomSigned();
	float x = 0;
	float y = 0;
	float angle = 0.0;

public:
	Bullet(bool IFF, sf::Vector2f spawnPoint);//---NOTE: requires different arguments from init of other enemy classes
	~Bullet();

	void init();
	void update(double deltaTime);
	bool isOutOfBounds();
	void setMoveVector(double deltaTime);
	void setAngle(double angle);
	void setSpawnPoint();
	void moveForward(double deltaTime);
	bool getIFF();//--------------use this to report bullet type (player or UFO) to collision detection functions
	sf::FloatRect getBounds();
};