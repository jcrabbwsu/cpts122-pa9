#include "Game.h"
#include "Level.h"
#include "Menu.h"

#include <iostream>

Game::Game()
	: window(new sf::RenderWindow(sf::VideoMode(1200, 800), "Asteroids"))
	, menu(new Menu())
	, level(nullptr) {
	initLevel();

	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	menu->setGame(this);
	menu->initInternal();
}

Game::~Game() {
	delete menu;
	delete level;
	delete window;
}

void Game::initLevel() {
	level = new Level(1, 1, 200);

	level->setGame(this);
	level->initInternal();
}

void Game::run() {
	sf::Clock clock;
	sf::Clock frameClock;
	short frameCount = 0;
	while (window->isOpen()) {
		input();
		render(clock.restart());//contains level update
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
	if (isAtMenu) {
		menu->updateInternal(deltaTime.asSeconds());
	} else {
		level->updateInternal(deltaTime.asSeconds());
	}
	window->display();
}

sf::RenderWindow *Game::getWindow() {
	return window;
}

Level *Game::getLevel() {
	return level;
}

void Game::transitionToGame() {
	initLevel();
	isAtMenu = false;
}

void Game::transitionToMenu() {
	isAtMenu = true;
}
