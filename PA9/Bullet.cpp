#include "Bullet.h"

#include <iostream>
#include <math.h>

Bullet::Bullet(bool IFF, sf::Vector2f spawnPoint, double offset) : offset(offset) {
	mIFF = IFF;
	mSpawnPoint = spawnPoint;
}

Bullet::~Bullet() {
}

void Bullet::init() {
	setMoveVector();
	circleShape = sf::CircleShape(5.0f);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setPosition(mSpawnPoint);
	circleShape.setOrigin(
		circleShape.getRadius(),
		circleShape.getRadius()
	);
}

void Bullet::update(double deltaTime) {
	offset += deltaTime;
	float sin = sinf(offset);
	float cos = cosf(offset);

	circleShape.move(mMoveVector);
	draw(circleShape);
}

void Bullet::setMoveVector()
{
	if (mIFF == false)//enemy bullet
	{
		sf::Vector2u windowSize = this->getGame()->getWindow()->getSize();//get the size of the window
		sf::Vector2u windowCenter; // set this to the center of the window
		windowCenter.x = windowSize.x / 2;
		windowCenter.y = windowSize.y / 2;

		mMoveVector.x = (windowCenter.x / 100) - (mSpawnPoint.x / 100);
		mMoveVector.y = (windowCenter.y / 100) - (mSpawnPoint.y / 100);
	}
}

void Bullet::setSpawnPoint()
{
}

bool Bullet::getIFF()
{
	return mIFF;
}

void Bullet::setOutOfBounds()
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

int Bullet::randomSigned() {
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
