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
	circleShape.setOrigin(
		circleShape.getRadius(),
		circleShape.getRadius()
	);
}

void Circle::update(double deltaTime) {
	offset += deltaTime;
	float sin = sinf(offset);
	float cos = cosf(offset);

	int midpointX = getWindow()->getSize().x / 2;
	int midpointY = getWindow()->getSize().y / 2;

	circleShape.setPosition(midpointX + midpointX * sin, midpointY + midpointY * cos);
	circleShape.setScale(abs(sin), abs(sin));

	sf::Color color = circleShape.getFillColor();
	color.r = (int)(255 * abs(sin));
	color.g = (int)(255 * abs(cos));
	color.b = (int)(255 * abs(sin));
	circleShape.setFillColor(color);

	draw(circleShape);
}
