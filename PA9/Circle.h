#pragma once

#include "GameObject.h"

class Circle : public GameObject {
	sf::CircleShape circleShape;
	double offset = 0;

public:
	Circle();
	~Circle();

	void init();
	void update(double deltaTime);
};
