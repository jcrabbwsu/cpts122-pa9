#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

class Level;

class Game {
	sf::RenderWindow *window;
	Level *level;

public:
	Game();
	~Game();
	
	void run();
	void input();
	void render(sf::Time deltaTime);

	sf::RenderWindow *getWindow();
};
