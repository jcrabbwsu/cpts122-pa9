#include "Ship.h"
#include "Game.h"
#include "Bullet.h"
#include "Level.h"
#include "Asteroid.h"
#include "UFO.h"

Ship::Ship() {
}

Ship::~Ship() {
}

void Ship::init() {
	auto windowSize = getGame()->getWindow()->getSize();
	sf::Vector2f location((float)windowSize.x / 2,
		(float)windowSize.y / 2);
	shipTexture.loadFromFile("ship.png");
	shipSprite = sf::Sprite(shipTexture);
	shipSprite.setScale(0.1, 0.1);
	shipSprite.setOrigin(
		shipTexture.getSize().x / 2,
		shipTexture.getSize().y / 2
	);
	shipSprite.setPosition(location);
}

void Ship::update(double deltaTime) {
	const float rotateScalar = 180.0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		moveForward(deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveForward(-deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shipSprite.rotate(-rotateScalar * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shipSprite.rotate(rotateScalar * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fire();
	}

	auto intersectingObjects = getGame()->getLevel()->getIntersectingChildren(this);

	for (auto intersect : intersectingObjects) {
		if (auto bullet = dynamic_cast<Bullet *>(intersect)) {
			if (!bullet->getIFF()) {
				dispose();
			}
		}
		if (auto asteroid = dynamic_cast<Asteroid *>(intersect)) {
			dispose();
		}
		if (auto ufo = dynamic_cast<UFO *>(intersect)) {
			dispose();
		}
	}

	draw(shipSprite);
}

void Ship::moveForward(double deltaTime) {
	float r = 500;
	x = 0;
	y = 0;
	float theta = (this->shipSprite.getRotation() - 90) * (3.1415 / 180.0);

	sf::Vector2f shipPosition = this->shipSprite.getPosition();

	x += r * cos(theta) * deltaTime;
	y += r * sin(theta) * deltaTime;

	this->shipSprite.move(x, y);
}

void Ship::turnLeft() {
}

void Ship::turnRight() {
}

void Ship::fire() {
	if (shootClock.getElapsedTime().asSeconds() < 0.3) {
		return;
	}
	auto bullet = new Bullet(true, shipSprite.getPosition());
	bullet->setAngle(shipSprite.getRotation());
	getGame()->getLevel()->addChildGameObject(
		bullet
	);
	shootClock.restart();
}

bool Ship::isOutOfBounds() {
	// TODO
	return false;
}

sf::FloatRect Ship::getBounds() {
	return shipSprite.getGlobalBounds();
}
