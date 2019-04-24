#include "Button.h"
#include "Game.h"

Button::Button(int width, int height, int x, int y, const char *str)
	: width(width), height(height), x(x), y(y), str(str) {
}

Button::~Button() {
}

void Button::init() {
	if (!font.loadFromFile("kongtext.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		abort();
	};

	border.setSize(sf::Vector2f(width, height));
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineThickness(5);
	border.setOutlineColor(sf::Color::White);

	text.setString(str);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
}

void Button::update(double deltaTime) {
	border.setPosition(x, y);
	text.setPosition(x - 10, y);

	//border.setSize(text.getLocalBounds().width, text.getLocalBounds().height);
	sf::FloatRect size = text.getLocalBounds();

	text.setOrigin(
		text.getGlobalBounds().width / 2,
		height / 2
	);
	border.setOrigin(
		border.getGlobalBounds().width / 2,
		border.getGlobalBounds().height / 2
	);
	border.setSize(sf::Vector2f(size.width + 50, size.height + 50));

	sf::FloatRect borderBounds = border.getGlobalBounds();
	sf::Vector2i mousePosition = mouse.getPosition(*getGame()->getWindow());
	if (mousePosition.x > borderBounds.left && mousePosition.x < borderBounds.left + borderBounds.width && mousePosition.y > borderBounds.top && mousePosition.y < borderBounds.top + borderBounds.height) {
		border.setFillColor(sf::Color(169, 169, 169));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			callback();
		}
	} else {
		border.setFillColor(sf::Color::Transparent);
	}

	draw(border);
	draw(text);
}

void Button::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Button::setCallback(ButtonCallback callback) {
	this->callback = callback;
}

sf::FloatRect Button::getBounds()
{
	return sf::FloatRect();
}

bool Button::isOutOfBounds()
{
	return false;
}
