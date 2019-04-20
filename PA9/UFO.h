#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Entity.h"

/**********************************************************
*  UFO CLASS
* GameObject -> Entity -> UFO
* This class is used for the UFO-type enemy.  They spawn at a 
* fixed rate from either the left or right window border,
* travel slowly and periodically fire bullets towards the
* center of the window.  Collision with player destroys the player,
* collision with "friendly"-type bullets (player bullets) destroys
* the UFO, granting points to the player.
**********************************************************/
class UFO : public Entity {
	sf::Vector2f mMoveVector;
	sf::Vector2f mSpawnPoint;
	int mSpawnWall;
	sf::Texture ufoTexture;
	sf::Sprite ufoSprite;
	int randomSigned();
	sf::FloatRect getBounds();
	sf::Clock shootClock;

public:
	UFO();
	~UFO();

	void init();
	void update(double deltaTime);
	bool isOutOfBounds();
	void setMoveVector();
	void setSpawnPoint();
	void setSpawnWall();
};