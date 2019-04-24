#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

#include <functional>

typedef std::function<void(void)> ButtonCallback;

class Button : public GameObject {
	sf::Font font;
	sf::RectangleShape border;
	sf::Text text;
	sf::Mouse mouse;

	int width;
	int height;
	int x;
	int y;
	const char *str;
	ButtonCallback callback;

public:
	Button(int width, int height, int x, int y, const char *text);
	~Button();

	void init();
	void update(double deltaTime);
	void setPosition(int x, int y);
	void setCallback(ButtonCallback callback);

	sf::FloatRect getBounds();
	bool isOutOfBounds();
};