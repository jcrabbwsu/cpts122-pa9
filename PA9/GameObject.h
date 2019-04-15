#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
	sf::RenderWindow *window;

public:
	GameObject();
	~GameObject();

	virtual void init() = 0;
	virtual void update(double deltaTime) = 0;

	void draw(sf::Drawable &drawable);
	sf::RenderWindow *getWindow();
	void setWindow(sf::RenderWindow *window);
};
