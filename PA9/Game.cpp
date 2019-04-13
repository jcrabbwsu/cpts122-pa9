#include "Game.h"
#include "Circle.h"

Game::Game() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "Game")) {
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	addGameObject(new Circle());
}

Game::~Game() {
	delete window;
}

void Game::run() {
	sf::Clock clock;
	while (window->isOpen()) {
		input();
		render(clock.restart());
	}
}

void Game::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}
}

void Game::render(sf::Time deltaTime) {
	window->clear(sf::Color::Black);
	for (auto gameObject : gameObjects) {
		gameObject->render(deltaTime.asMilliseconds());
	}
	window->display();
}

void Game::addGameObject(GameObject *gameObject) {
	gameObject->setWindow(window);
	gameObject->init();
	gameObjects.push_back(gameObject);
}
