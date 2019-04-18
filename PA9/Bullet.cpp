#include "Bullet.h"

#include <iostream>
#include <math.h>

//IFF: true for player bullets, false for UFO bullets
//spawnPoint: use circleShape.getPosition() for the spawning object (player or UFO)
//offset: Logan can fill this in?
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
	circleShape.move(mMoveVector);//moves the bullet
	draw(circleShape);//draws the bullet
}

void Bullet::setMoveVector()
{
	if (mIFF == false)//UFO bullet
	{
		const int bulletSpeed1 = 100;//use to adjust bullet speed

		sf::Vector2u windowSize = this->getGame()->getWindow()->getSize();//get the size of the window
		sf::Vector2u windowCenter; // set this to the center of the window
		windowCenter.x = windowSize.x / 2;
		windowCenter.y = windowSize.y / 2;

		//numerator in each term sets the direction to middle of the screen, denominator controls speed of movement
		mMoveVector.x = (windowCenter.x / bulletSpeed1) - (mSpawnPoint.x / bulletSpeed1);
		mMoveVector.y = (windowCenter.y / bulletSpeed1) - (mSpawnPoint.y / bulletSpeed1);
	}
	else//player bullet
	{
		int bulletSpeed2 = 75; //use to adjust bullet speed

	}
}

//not used for Bullet, set when new Bullet is created
void Bullet::setSpawnPoint()
{
}

bool Bullet::getIFF()
{
	return mIFF;
}

//mark object for destruction after it has moved beyond the window borders
void Bullet::setOutOfBounds()
{
	const sf::Vector2f currentPos = this->circleShape.getPosition();//get current position of object being checked
	const sf::Vector2u windowBounds = this->getGame()->getWindow()->getSize();//get window size
	const int offset = 10;

	if (currentPos.x < 0 - offset)//check if outside left border
	{
		mOutOfBounds = true;
	}
	else if (currentPos.x > windowBounds.x + offset)// check if outside right border
	{
		mOutOfBounds = true;
	}
	else if (currentPos.y < 0 - offset)//check if outside top border
	{
		mOutOfBounds = true;
	}
	else if (currentPos.y > windowBounds.y + offset)//check if outside bottom border
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
