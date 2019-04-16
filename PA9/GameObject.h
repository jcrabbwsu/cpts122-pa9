#pragma once

#include <SFML/Graphics.hpp>

class Game;

class GameObject {
	Game *game;
	std::vector<GameObject *> children;

public:
	GameObject();
	~GameObject();

	virtual void init() = 0;
	virtual void update(double deltaTime) = 0;

	void initInternal();
	void updateInternal(double deltaTime);
	void draw(sf::Drawable &drawable);
	Game *getGame();
	void setGame(Game *game);
	void addChildGameObject(GameObject *gameObject);
};
