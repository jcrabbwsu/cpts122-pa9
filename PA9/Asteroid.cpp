#include "Asteroid.h"
#include "Game.h"
#include "Level.h"
#include "Bullet.h"

#include <iostream>
#include <math.h>

Asteroid::Asteroid() {
}

Asteroid::~Asteroid() {
}

void Asteroid::init() {
	setSpawnWall();//randomly choose top/left/bottom/right window border
	setSpawnPoint();//choose random location on the spawn wall
	setMoveVector();//set a random vector that travels at some angle into the room
	spinDirection = rand() % 2;
	spinScale = rand() % 4;
	asteroidTexture.loadFromFile("alien.png");
	asteroidSprite.setTexture(asteroidTexture);
	asteroidSprite.setScale(0.1, 0.1);
	asteroidSprite.setOrigin(
		asteroidTexture.getSize().x / 2,
		asteroidTexture.getSize().y / 2
	);
	asteroidSprite.setPosition(mSpawnPoint);
}

void Asteroid::update(double deltaTime) {
	asteroidSprite.rotate(deltaTime * 40 * spinScale * spinDirection ? 1 : -1);
	asteroidSprite.move(mMoveVector);

	auto intersectingObjects = getGame()->getLevel()->getIntersectingChildren(this);

	for (auto intersect : intersectingObjects) {
		if (auto bullet = dynamic_cast<Bullet *>(intersect)) {
			getGame()->getLevel()->getScoreboard()->addToScore(2);
			dispose();
		}
	}

	draw(asteroidSprite);
}

void Asteroid::setMoveVector() {
	//the ratio of the first term in each vector value (x,y) determines the angle, second term sets the speed
	//and randomSigned() allows the angle to randomly be up/down or left/right depending on the wall spawning the object
	
	const int asteroidSpeed = 2000; // use to adjust asteroid speed, larger speed value = slower asteroid movement speed
	int asteroidAngle = (rand() % 4) + 1;//sets a random trajectory for the asteroid

	switch (mSpawnWall) {
	case 0://spawn from left wall
		mMoveVector = sf::Vector2f((asteroidAngle)*(1 / asteroidSpeed + 1),
			(asteroidAngle)*(1 / asteroidSpeed + 1)*(randomSigned()));
		break;
	case 1://spawn from top wall
		mMoveVector = sf::Vector2f((asteroidAngle)*(1 / asteroidSpeed + 1)*(randomSigned()),
			(asteroidAngle)*(1 / asteroidSpeed + 1));
		break;
	case 2://spawn from right wall
		mMoveVector = sf::Vector2f((asteroidAngle)*(1 / asteroidSpeed + 1)* -1 ,
			(asteroidAngle)*(1 / asteroidSpeed + 1)*(randomSigned()));
		break;
	case 3://spawn from bottom wall
		mMoveVector = sf::Vector2f((asteroidAngle)*(1 / asteroidSpeed + 1)*(randomSigned()),
			(asteroidAngle)*(1 / asteroidSpeed + 1) * -1);
		break;
	default:
		mMoveVector = sf::Vector2f(0, 0);
		break;
	}
}

void Asteroid::setSpawnPoint() {
	sf::Vector2u windowSize = this->getGame()->getWindow()->getSize();

	switch (mSpawnWall)
	{
	case 0://spawn from left wall
		mSpawnPoint = sf::Vector2f(0, rand() % windowSize.y);
		break;
	case 1://spawn from top wall
		mSpawnPoint = sf::Vector2f(rand() % windowSize.x , 0);
		break;
	case 2://spawn from right wall
		mSpawnPoint = sf::Vector2f(windowSize.x, rand() % windowSize.y);
		break;
	case 3://spawn from bottom wall
		mSpawnPoint = sf::Vector2f(rand() % windowSize.x, windowSize.y);
		break;
	default:
		mSpawnPoint = sf::Vector2f(0, 0);
		break;
	}
}

void Asteroid::setSpawnWall() {
	mSpawnWall = rand() % 4;
}

bool Asteroid::isOutOfBounds() {
	const sf::Vector2f currentPos = this->asteroidSprite.getPosition();
	const sf::Vector2u windowBounds = this->getGame()->getWindow()->getSize();
	const int offset = 10;

	if (currentPos.x < 0 - offset) {
		return true;
	} else if (currentPos.x > windowBounds.x + offset) {
		return true;
	} else if (currentPos.y < 0 - offset) {
		return true;
	} else if (currentPos.y > windowBounds.y + offset) {
		return true;
	}
	return false;
}

int Asteroid::randomSigned() {
	int flip = rand() % 2;

	if (flip == 0) {
		return -1;
	} else {
		return 1;
	}
}

sf::FloatRect Asteroid::getBounds() {
	return asteroidSprite.getGlobalBounds();
}
