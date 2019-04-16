#pragma once

#include "GameObject.h"
#include "Scoreboard.h"

#include <SFML/Graphics.hpp>

#include <vector>

class Game {
	sf::RenderWindow *window;
	Scoreboard *scoreboard;
	std::vector<GameObject *> gameObjects;

public:
	Game();
	~Game();
	
	void run();
	void input();
	void render(sf::Time deltaTime);
	void addGameObject(GameObject *gameObject);
};
