#include "Ship.h"

/*
if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
{
p1Paddle.move(0, -.01);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
p2Paddle.move(0, -.01);
}
*/

Ship::Ship(sf::Vector2f &size, sf::Color color, sf::Vector2f &spawnPoint, float rotationAngle) {
	this->mSize = size;
	this->mColor = color;
	this->mPosition = spawnPoint;
	this->mFacing = rotationAngle;
}

Ship::~Ship() {
	delete this;
}

void Ship::moveForward() {
	//sf::Vector2f facing = ();
	//this->shipShape.move(facing);
}

void Ship::turnLeft() {
	this->shipShape.setRotation(--mFacing);
}

void Ship::turnRight() {
	this->shipShape.setRotation(++mFacing);
}

void Ship::fire() {

}

void Ship::init() {
	this->shipShape = sf::RectangleShape(this->mSize);
	this->shipShape.setFillColor(this->mColor);
	this->shipShape.setPosition(this->mPosition);
}

void Ship::update(double deltaTime) {
	this->draw(shipShape);
}