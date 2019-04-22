#include "Background.h"

Background::Background()
{
}

Background::~Background()
{
}

void Background::init()
{
	backgroundTexture.loadFromFile("asteroidsbg.png");
	backgroundSprite.setTexture(backgroundTexture);
}

void Background::update(double deltaTime)
{
	draw(backgroundSprite);
}

bool Background::isOutOfBounds()
{
	return false;
}

sf::FloatRect Background::getBounds()
{
	return sf::FloatRect();
}
