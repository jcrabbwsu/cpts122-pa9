#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Button : public GameObject, public sf::RectangleShape
{
public:
	Button();
	~Button();

	sf::RectangleShape button;

	void init();
	void update(double deltaTime);

	sf::FloatRect getBounds();
	bool isOutOfBounds();
};