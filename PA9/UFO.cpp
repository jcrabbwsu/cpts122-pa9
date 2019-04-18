#include "UFO.h"
#include "Bullet.h"

#include <iostream>
#include <math.h>

UFO::UFO(double offset) : offset(offset) {
}

UFO::~UFO() {
}

void UFO::init() {
	shotCounter = 0;
	setSpawnWall();
	setSpawnPoint();
	setMoveVector();
	circleShape = sf::CircleShape(100.0f);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setPosition(mSpawnPoint);
	circleShape.setOrigin(
		circleShape.getRadius(),
		circleShape.getRadius()
	);
}

void UFO::update(double deltaTime) {
	offset += deltaTime;
	float sin = sinf(offset);
	float cos = cosf(offset);

	circleShape.move(mMoveVector);

	sf::Color color = circleShape.getFillColor();
	color.r = (int)(255 * abs(sin));
	color.g = (int)(255 * abs(cos));
	color.b = (int)(255 * abs(sin));
	circleShape.setFillColor(color);

	shotCounter++;

	if (shotCounter % 100 == 0)
	{
		addChildGameObject(new Bullet(false, circleShape.getPosition(), 0.0));
	}

	draw(circleShape);
}

void UFO::setMoveVector()
{
	//the ratio of the first term in each vector value (x,y) determines the angle, second term sets the speed
	//and randomSigned() allows the angle to randomly be up/down or left/right depending on the wall spawning the object

	switch (mSpawnWall)
	{
	case 0://spawn from left wall
		mMoveVector = sf::Vector2f(3,0);
		break;
	case 1://spawn from right wall
		mMoveVector = sf::Vector2f(-3,0);
		break;
	default:
		mMoveVector = sf::Vector2f(0, 0);
		break;
	}
}

void UFO::setSpawnPoint()
{
	sf::Vector2u windowSize = this->getGame()->getWindow()->getSize();

	switch (mSpawnWall)
	{
	case 0://spawn from left wall
		mSpawnPoint = sf::Vector2f(0, rand() % windowSize.y);
		break;
	case 1://spawn from right wall
		mSpawnPoint = sf::Vector2f(windowSize.x, rand() % windowSize.y);
		break;
	default:
		mSpawnPoint = sf::Vector2f(0, 0);
		break;
	}
}

void UFO::setSpawnWall() {
	mSpawnWall = rand() % 2;
}

void UFO::setOutOfBounds()
{
	const sf::Vector2f currentPos = this->circleShape.getPosition();
	const sf::Vector2u windowBounds = this->getGame()->getWindow()->getSize();
	const int offset = 10;

	if (currentPos.x < 0 - offset)
	{
		mOutOfBounds = true;
	}
	else if (currentPos.x > windowBounds.x + offset)
	{
		mOutOfBounds = true;
	}
	else if (currentPos.y < 0 - offset)
	{
		mOutOfBounds = true;
	}
	else if (currentPos.y > windowBounds.y + offset)
	{
		mOutOfBounds = true;
	}

}

int UFO::randomSigned() {
	int flip = rand() % 2;

	if (flip == 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
