#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Button.h"

class Menu : public GameObject {
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	sf::Font font;
	sf::Text rulesText;
	Button *playButton;
	Button *scoresButton;
	Button *exitButton;

public:
	Menu();
	~Menu();

	void init();
	void update(double deltaTime);

	sf::FloatRect getBounds();
	bool isOutOfBounds();
};