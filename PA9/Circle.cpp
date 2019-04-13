#include "Circle.h"

#include <iostream>
#include <math.h>

Circle::Circle() {
}

Circle::~Circle() {
}

void Circle::init() {
	circleShape = sf::CircleShape(100.0f);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setOrigin(100.0f, 100.0f);
}

void Circle::update(int deltaTime) {
	offset += deltaTime;
	float sin = sinf(offset * 0.001);
	float cos = cosf(offset * 0.001);

	int midpointX = getWindow()->getSize().x / 2;
	int midpointY = getWindow()->getSize().y / 2;

	circleShape.setPosition(midpointX + midpointX * sin, midpointY + midpointY * cos);

	sf::Color color = circleShape.getFillColor();
	color.r = (int)(255 * abs(sin));
	color.g = (int)(255 * abs(cos));
	color.b = (int)(255 * abs(sin));
	circleShape.setFillColor(color);

	draw(circleShape);
}
