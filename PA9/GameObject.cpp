#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

void GameObject::draw(sf::Drawable &drawable) {
	window->draw(drawable);
}

sf::RenderWindow *GameObject::getWindow() {
	return window;
}

void GameObject::setWindow(sf::RenderWindow *window) {
	this->window = window;
}
