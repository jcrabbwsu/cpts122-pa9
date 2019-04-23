#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Button.h"

class Menu : public GameObject
{
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	sf::Font font;
	sf::Text rulesText;
	Button newGameButton;
	Button ScoreboardButton;
	Button exitButton;
	sf::Text newGameButtonText;
	sf::Text ScoreboardButtonText;
	sf::Text exitButtonText;

public:
	Menu();
	void printMenu();

	void init();
	void update(double deltaTime);

	sf::FloatRect getBounds();
	bool isOutOfBounds();
};