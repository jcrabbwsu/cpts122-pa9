#pragma once

#include <SFML/Graphics.hpp>

class Ship : public sf::CircleShape
{
	Ship(sf::Vector2f &size, sf::Color color, sf::Vector2f &position) : sf::CircleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(position);
	}
	
	void moveForward();
	void turnLeft();
	void turnRight();

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
};