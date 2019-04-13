#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

#include <vector>

class Game {
	sf::RenderWindow *window;
	std::vector<GameObject *> gameObjects;

public:
	Game();
	~Game();
	
	void run();
	void input();
	void render(sf::Time deltaTime);
	void addGameObject(GameObject *gameObject);
};
