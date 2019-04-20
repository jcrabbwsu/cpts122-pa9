#include "Bullet.h"

#include <iostream>
#include <math.h>

//IFF: true for player bullets, false for UFO bullets
//spawnPoint: use bulletShape.getPosition() for the spawning object (player or UFO)
//offset: Logan can fill this in?
Bullet::Bullet(bool IFF, sf::Vector2f spawnPoint) {
	mIFF = IFF;
	mSpawnPoint = spawnPoint;
}

Bullet::~Bullet() {
}

void Bullet::init() {
	setMoveVector(0);
	bulletShape = sf::CircleShape(5.0f);
	bulletShape.setFillColor(sf::Color::White);
	bulletShape.setPosition(mSpawnPoint);
	bulletShape.setOrigin(
		bulletShape.getRadius(),
		bulletShape.getRadius()
	);
}

void Bullet::update(double deltaTime) {
	if (mIFF) {
		moveForward(deltaTime);
	}
	bulletShape.move(mMoveVector);

	draw(bulletShape);//draws the bullet
}

void Bullet::setMoveVector(double deltaTime)
{
	// If UFO bullet
	if (mIFF == false) {
		const int bulletSpeed1 = 100;//use to adjust bullet speed

		sf::Vector2u windowSize = this->getGame()->getWindow()->getSize();//get the size of the window
		sf::Vector2u windowCenter; // set this to the center of the window
		windowCenter.x = windowSize.x / 2;
		windowCenter.y = windowSize.y / 2;

		//numerator in each term sets the direction to middle of the screen, denominator controls speed of movement
		mMoveVector.x = (windowCenter.x / bulletSpeed1) - (mSpawnPoint.x / bulletSpeed1);
		mMoveVector.y = (windowCenter.y / bulletSpeed1) - (mSpawnPoint.y / bulletSpeed1);
	}
}

void Bullet::moveForward(double deltaTime) {
	float r = 750;
	x = 0;
	y = 0;
	float theta = (angle - 90) * (3.1415 / 180.0);

	sf::Vector2f shipPosition = bulletShape.getPosition();

	x += r * cos(theta) * deltaTime;
	y += r * sin(theta) * deltaTime;

	//bulletShape.move(x, y);
	mMoveVector = sf::Vector2f(x, y);
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
bool Bullet::isOutOfBounds()
{
	const sf::Vector2f currentPos = this->bulletShape.getPosition();//get current position of object being checked
	const sf::Vector2u windowBounds = this->getGame()->getWindow()->getSize();//get window size
	const int offset = 10;

	if (currentPos.x < 0 - offset)//check if outside left border
	{
		return true;
	}
	else if (currentPos.x > windowBounds.x + offset)// check if outside right border
	{
		return true;
	}
	else if (currentPos.y < 0 - offset)//check if outside top border
	{
		return true;
	}
	else if (currentPos.y > windowBounds.y + offset)//check if outside bottom border
	{
		return true;
	}
	return false;
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

void Bullet::setAngle(double angle) {
	this->angle = angle;
}

sf::FloatRect Bullet::getBounds() {
	return bulletShape.getGlobalBounds();
}
