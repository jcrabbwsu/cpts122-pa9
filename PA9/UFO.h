#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Enemies.h"

/**********************************************************
*  UFO CLASS
* GameObject -> Enemies -> UFO
* This class is used for the UFO-type enemy.  They spawn at a 
* fixed rate from either the left or right window border,
* travel slowly and periodically fire bullets towards the
* center of the window.  Collision with player destroys the player,
* collision with "friendly"-type bullets (player bullets) destroys
* the UFO, granting points to the player.
**********************************************************/

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