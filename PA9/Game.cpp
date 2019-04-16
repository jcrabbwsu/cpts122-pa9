#include "Game.h"
#include "Circle.h"

#include <iostream>

Game::Game() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "Game")) {
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	scoreboard = new Scoreboard();

	addGameObject(scoreboard);
	addGameObject(new Circle());
	addGameObject(new Circle(1000));
}

Game::~Game() {
	delete scoreboard;
	delete window;
}

void Game::run() {
	sf::Clock clock;
	sf::Clock frameClock;
	short frameCount = 0;
	while (window->isOpen()) {
		input();
		render(clock.restart());
		frameCount++;
		if (frameClock.getElapsedTime().asMilliseconds() > 999) {
			std::cout << "FPS: " << frameCount << std::endl;
			frameCount = 0;
			frameClock.restart();
		}
	}
}

void Game::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window->setView(sf::View(visibleArea));
		}
	}
}

void Game::render(sf::Time deltaTime) {
	window->clear(sf::Color::Black);
	for (auto gameObject : gameObjects) {
		gameObject->update(deltaTime.asSeconds());
	}
	window->display();
}

void Game::addGameObject(GameObject *gameObject) {
	gameObject->setWindow(window);
	gameObject->init();
	gameObjects.push_back(gameObject);
}
