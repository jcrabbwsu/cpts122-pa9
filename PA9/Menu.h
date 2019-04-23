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
	Button newGameButton;
	Button scoreboardButton;
	Button exitButton;
	sf::Text newGameButtonText;
	sf::Text scoreboardButtonText;
	sf::Text exitButtonText;
	sf::Mouse cursor;

public:
	Menu();
	~Menu();

	void init();
	void update(double deltaTime);

	sf::FloatRect getBounds();
	bool isOutOfBounds();
};