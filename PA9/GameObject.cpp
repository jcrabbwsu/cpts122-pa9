#include "GameObject.h"
#include "Game.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

void GameObject::initInternal() {
	init();

	for (auto child : children) {
		child->initInternal();
	}
}

void GameObject::updateInternal(double deltaTime) {
	update(deltaTime);

	for (auto child : children) {
		child->updateInternal(deltaTime);
	}
}

void GameObject::draw(sf::Drawable &drawable) {
	game->getWindow()->draw(drawable);
}

Game *GameObject::getGame() {
	return game;
}

void GameObject::setGame(Game *game) {
	this->game = game;
}

void GameObject::addChildGameObject(GameObject *gameObject) {
	gameObject->setGame(game);
	gameObject->init();
	children.push_back(gameObject);
}
