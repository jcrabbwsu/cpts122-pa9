#include "Circle.h"

#include <iostream>
#include <math.h>

Circle::Circle(double offset) : offset(offset) {
	setSpawnWall();
	setSpawnPoint();
	setMoveVector();
}

Circle::~Circle() {
}

void Circle::init() {
	circleShape = sf::CircleShape(25.0f);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setPosition(mSpawnPoint);
	circleShape.setOrigin(
		circleShape.getRadius(),
		circleShape.getRadius()
	);
}

void Circle::update(double deltaTime) {
	offset += deltaTime;
	float sin = sinf(offset);
	float cos = cosf(offset);

	circleShape.move(mMoveVector);

	sf::Color color = circleShape.getFillColor();
	color.r = (int)(255 * abs(sin));
	color.g = (int)(255 * abs(cos));
	color.b = (int)(255 * abs(sin));
	circleShape.setFillColor(color);

	draw(circleShape);
}

void Circle::setMoveVector()
{
	//the ratio of the first term in each vector value (x,y) determines the angle, second term sets the speed
	//and randomSigned() allows the angle to randomly be up/down or left/right depending on the wall spawning the object
	
	switch (mSpawnWall)
	{
	case 0://spawn from left wall
		mMoveVector = sf::Vector2f((/*first term*/(rand() % 10) + 1)*/*second term*/(1 / rand() % 100 + 1),
			((rand() % 10) + 1)*(1 / rand() % 100 + 1)*(randomSigned()));
		break;
	case 1://spawn from top wall
		mMoveVector = sf::Vector2f(((rand() % 10) + 1)*(1 / rand() % 100 + 1)*(randomSigned()),
			((rand() % 10) + 1)*(1 / rand() % 100 + 1));
		break;
	case 2://spawn from right wall
		mMoveVector = sf::Vector2f(((rand() % 10) + 1)*(1 / rand() % 100 + 1)* -1 ,
			((rand() % 10) + 1)*(1 / rand() % 100 + 1)*(randomSigned()));
		break;
	case 3://spawn from bottom wall
		mMoveVector = sf::Vector2f(((rand() % 10) + 1)*(1 / rand() % 100 + 1)*(randomSigned()),
			((rand() % 10) + 1)*(1 / rand() % 100 + 1) * -1);
		break;
	default:
		mMoveVector = sf::Vector2f(0, 0);
		break;
	}
}

void Circle::setSpawnPoint()
{
	switch (mSpawnWall)
	{
	case 0://spawn from left wall
		mSpawnPoint = sf::Vector2f(0, rand() % 800);
		break;
	case 1://spawn from top wall
		mSpawnPoint = sf::Vector2f(rand() % 1200 , 0);
		break;
	case 2://spawn from right wall
		mSpawnPoint = sf::Vector2f(1200, rand() % 800);
		break;
	case 3://spawn from bottom wall
		mSpawnPoint = sf::Vector2f(rand() % 1200, 800);
		break;
	default:
		mSpawnPoint = sf::Vector2f(0, 0);
		break;
	}
}

void Circle::setSpawnWall() {
	mSpawnWall = rand() % 4;
}

int Circle::randomSigned() {
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
