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
}

void Circle::render(int deltaTime) {
	offset += deltaTime;

	sf::Color color = circleShape.getFillColor();
	color.a = (int)(255 * abs(sinf(offset * 0.001)));
	circleShape.setFillColor(color);

	std::cout << offset << std::endl;

	draw(circleShape);
}
