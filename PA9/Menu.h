#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"


class Menu : public GameObject
{
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	sf::Font font;
	sf::Text rulesText;

public:
	Menu();
	void printMenu();

	void init();
	void update(double deltaTime);

	sf::FloatRect getBounds();
	bool isOutOfBounds();
};