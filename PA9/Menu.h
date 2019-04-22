#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"


class Menu : public GameObject
{
public:
	sf::Font font;
	sf::Text menuText;

	Menu();
	void printMenu();

	void init();
	void update(double deltaTime);

	sf::FloatRect getBounds();
	bool isOutOfBounds();
};