#include "Enemies.h"


//constructor for enemies class
Enemies::Enemies(float moveSpeed, sf::Vector2f & spawnPoint, sf::Color & color)
{
	this->mMoveVector = moveSpeed;
	this->mSpawnPoint = spawnPoint;
	this->mColor = color;
	//sets random radius size
	setSize();
}

//default constructor for enemies class
Enemies::Enemies()
{
	this->mColor = sf::Color::White;
	setSize();
}

//destructor for enemies class
Enemies::~Enemies()
{
	delete this;
}

//generates a random radius length for the size of the enemy
void Enemies::setSize()
{
	float radius = 0.f;

	//generate random number from 15-55
	while (radius > 55 || radius < 15)
	{
		radius = rand() % 55;
	}

	this->mSize = radius;

}

//initializes different aspects of the enemy
void Enemies::init()
{
	this->enemyShape = sf::CircleShape(this->mSize);
	this->enemyShape.setFillColor(this->mColor);
	this->enemyShape.setPosition(this->mSpawnPoint);
}

void Enemies::update(double deltaTime)
{
	draw(this->enemyShape);
}

void Enemies::setOutOfBounds()
{
}
