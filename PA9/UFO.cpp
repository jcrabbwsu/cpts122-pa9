#include "UFO.h"
#include "Bullet.h"
#include "Game.h"
#include "Level.h"

#include <iostream>
#include <math.h>

UFO::UFO() {
}

UFO::~UFO() {
}

void UFO::init() {
	setSpawnWall(); //for UFO class this top/bottom left or top/bottom right
	setSpawnPoint();
	setMoveVector(); //either straight left or straight right from spawn point

	ufoTexture.loadFromFile("alien.png");
	ufoSprite.setTexture(ufoTexture);
	ufoSprite.setScale(0.2, 0.2);
	ufoSprite.setOrigin(
		ufoTexture.getSize().x / 2,
		ufoTexture.getSize().y / 2
	);
	ufoSprite.setPosition(mSpawnPoint);//set initial position as determined by spawn point
}

void UFO::update(double deltaTime) {
	ufoSprite.move(mMoveVector);

	if (shootClock.getElapsedTime().asMilliseconds() > 1250) {
		getGame()->getLevel()->addChildGameObject(
			new Bullet(false, ufoSprite.getPosition())
		);
		shootClock.restart();
	}

	auto intersectingObjects = getGame()->getLevel()->getIntersectingChildren(this);

	for (auto intersect : intersectingObjects) {
		if (auto bullet = dynamic_cast<Bullet *>(intersect)) {
			if (bullet->getIFF()) {
				dispose();
			}
		}
	}

	draw(ufoSprite);
}

void UFO::setMoveVector()
{
	switch (mSpawnWall) {
	case 0://spawn from top left wall
		mMoveVector = sf::Vector2f(4,0);
		break;
	case 1://spawn from bottom left wall
		mMoveVector = sf::Vector2f(4, 0);
		break;
	case 2://spawn from top right wall
		mMoveVector = sf::Vector2f(-4,0);
		break;
	case 3://spawn from bottom right wall
		mMoveVector = sf::Vector2f(-4, 0);
		break;
	default:
		mMoveVector = sf::Vector2f(0, 0);
		break;
	}
}

void UFO::setSpawnPoint() {
	sf::Vector2u windowSize = this->getGame()->getWindow()->getSize();

	switch (mSpawnWall) {
	case 0: //spawn from top left wall
		mSpawnPoint = sf::Vector2f(0, 100);
		break;
	case 1: //spawn from bottom left wall
		mSpawnPoint = sf::Vector2f(0, windowSize.y - 100);
		break;
	case 2: //spawn from top right wall
		mSpawnPoint = sf::Vector2f(windowSize.x, 100);
		break;
	case 3: //spawn from bottom right wall
		mSpawnPoint = sf::Vector2f(windowSize.x, windowSize.y - 100);
		break;
	default:
		mSpawnPoint = sf::Vector2f(0, 0);
		break;
	}
}

void UFO::setSpawnWall() {
	mSpawnWall = rand() % 4;//set spawn location randomly to one of four possible locations
}

//see comments in Bullet.cpp
bool UFO::isOutOfBounds() {
	const sf::Vector2f currentPos = this->ufoSprite.getPosition();
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

int UFO::randomSigned() {
	int flip = rand() % 2;

	if (flip == 0) {
		return -1;
	} else {
		return 1;
	}
}

sf::FloatRect UFO::getBounds() {
	return ufoSprite.getGlobalBounds();
}
