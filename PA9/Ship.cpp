#include "Ship.h"

Ship::Ship(sf::Vector2f &size, sf::Color color, sf::Vector2f &spawnPoint, float rotationAngle) {
	this->mSize = size;
	this->mColor = color;
	this->mPosition = spawnPoint;
	this->mFacing = rotationAngle;
	//this->mBoundary = (window.getsize().x, window.getsize().y)
}

Ship::~Ship() {
	delete this;
}

void Ship::moveForward() {
	float r = 2.0, X = 0.0, Y = 0.0;
	float theta = this->shipShape.getRotation();

	sf::Vector2f shipPosition = this->shipShape.getPosition();

	X = r*cos(theta);
	Y = r*sin(theta);

	this->shipShape.move(X + shipPosition.x, Y + shipPosition.y);
}

void Ship::turnLeft() {
	this->shipShape.setRotation(--mFacing);
}

void Ship::turnRight() {
	this->shipShape.setRotation(++mFacing);
}

void Ship::fire() {
	//new Bullet(true, this->shipShape.getPosition(), )
}

void Ship::init() {
	this->shipShape = sf::RectangleShape(this->mSize);
	this->shipShape.setFillColor(this->mColor);
	this->shipShape.setPosition(this->mPosition);
}

void Ship::update(double deltaTime) {
	GameObject::draw(shipShape);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		moveForward();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		turnLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		turnRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fire();
	}
}

void Ship::setOutOfBounds()
{

}