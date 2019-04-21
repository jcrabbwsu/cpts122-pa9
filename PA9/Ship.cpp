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

	//playerShield is displayed while player is invincible after respawn
	playerShield = new sf::CircleShape(50,50);
	shieldColor = new sf::Color(255, 255, 0, 255);
	playerShield->setOutlineThickness(10);
	playerShield->setOutlineColor(*shieldColor);
	playerShield->setFillColor(sf::Color::Transparent);
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

	if (respawnClock.getElapsedTime().asSeconds() > 3)
	{
		for (auto intersect : intersectingObjects) {
			if (auto bullet = dynamic_cast<Bullet *>(intersect)) {
				if (!bullet->getIFF()) {
					getGame()->getLevel()->getScoreboard()->setLives(-1);
					respawnClock.restart();
				}
			}
			if (auto asteroid = dynamic_cast<Asteroid *>(intersect)) {
				getGame()->getLevel()->getScoreboard()->setLives(-1);
				respawnClock.restart();
			}
			if (auto ufo = dynamic_cast<UFO *>(intersect)) {
				getGame()->getLevel()->getScoreboard()->setLives(-1);
				respawnClock.restart();
			}
		}
	}

	//draw the shield while player is invincible NOTE: maxLives is set in scoreboard.h
	if (respawnClock.getElapsedTime().asSeconds() < 3 && getGame()->getLevel()->getScoreboard()->getLives()
		< getGame()->getLevel()->getScoreboard()->getMaxLives())
	{
		playerShield->setPosition(shipSprite.getPosition().x - 50, shipSprite.getPosition().y - 50);
		draw(*playerShield);
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
	const sf::Vector2f currentPos = this->shipSprite.getPosition();//get current position of object being checked
	const sf::Vector2u windowBounds = this->getGame()->getWindow()->getSize();//get window size
	const int offset = 10;

	if (currentPos.x < 0 - offset)//check if outside left border
	{
		this->shipSprite.setPosition(windowBounds.x, currentPos.y);
	}
	else if (currentPos.x > windowBounds.x + offset)// check if outside right border
	{
		this->shipSprite.setPosition(0, currentPos.y);
	}
	else if (currentPos.y < 0 - offset)//check if outside top border
	{
		this->shipSprite.setPosition(currentPos.x, windowBounds.y);
	}
	else if (currentPos.y > windowBounds.y + offset)//check if outside bottom border
	{
		this->shipSprite.setPosition(currentPos.x, 0);
	}
	return false;
}

sf::FloatRect Ship::getBounds() {
	return shipSprite.getGlobalBounds();
}

sf::Clock Ship::getRespawnClock()
{
	return respawnClock;
}

sf::Sprite Ship::getShipSprite()
{
	return shipSprite;
}
