#pragma once

#include "GameObject.h"
#include <math.h>

class Background : public GameObject {
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

public:
	Background();
	~Background();

	void init();
	void update(double deltaTime);
	bool isOutOfBounds();
	sf::FloatRect getBounds();
};