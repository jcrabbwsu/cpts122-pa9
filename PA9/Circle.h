#pragma once

#include "GameObject.h"

class Circle : public GameObject {
	sf::CircleShape circleShape;
	int offset = 0;

public:
	Circle();
	~Circle();

	void init();
	void render(int deltaTime);
};
