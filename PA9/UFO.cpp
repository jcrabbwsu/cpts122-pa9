#include "UFO.h"
#include "Bullet.h"

#include <iostream>
#include <math.h>

UFO::UFO(double offset) : offset(offset) {
}

UFO::~UFO() {
}

void UFO::init() {
	shotCounter = 0;//determines whether UFO fires a bullet or not
	setSpawnWall();//for UFO class this top/bottom left or top/bottom right
	setSpawnPoint();
	setMoveVector();//either straight left or straight right from spawn point
	circleShape = sf::CircleShape(75.0f);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setPosition(mSpawnPoint);//set initial position as determined by spawn point
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

	shotCounter++;//increment shot counter each cycle

	if (shotCounter % 75 == 0)//fire a bullet every 75 cycles
	{
		addChildGameObject(new Bullet(false, circleShape.getPosition(), 0.0));
	}

	draw(circleShape);
}

void UFO::setMoveVector()
{
	switch (mSpawnWall)
	{
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

void UFO::setSpawnPoint()
{
	sf::Vector2u windowSize = this->getGame()->getWindow()->getSize();

	switch (mSpawnWall)
	{
	case 0://spawn from top left wall
		mSpawnPoint = sf::Vector2f(0, 100);
		break;
	case 1://spawn from bottom left wall
		mSpawnPoint = sf::Vector2f(0, windowSize.y - 100);
		break;
	case 2://spawn from top right wall
		mSpawnPoint = sf::Vector2f(windowSize.x, 100);
		break;
	case 3://spawn from bottom right wall
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
