#include "Game.h"
#include "Level.h"
#include "Menu.h"
#include "ScoreSubmitter.h"
#include "ScoreSubmissionScreen.h"
#include "ScoreViewScreen.h"

#include <iostream>

Game::Game()
	: window(new sf::RenderWindow(sf::VideoMode(1200, 800), "Asteroids"))
	, menu(new Menu())
	, level(nullptr)
	, scoreSubmitter(new ScoreSubmitter(this))
	, submissionScreen(nullptr)
	, scoreScreen(nullptr) {
	initLevel();
	initSubmissionScreen();
	initScoreViewScreen();

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
	level = new Level(1, 1, 100);
	level->setGame(this);
	level->initInternal();
}

void Game::initSubmissionScreen() {
	submissionScreen = new ScoreSubmissionScreen();
	submissionScreen->setScore(0);

	submissionScreen->setGame(this);
	submissionScreen->initInternal();
}

void Game::initScoreViewScreen() {
	scoreScreen = new ScoreViewScreen();

	scoreScreen->setGame(this);
	scoreScreen->initInternal();
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
		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode >= 32 && event.text.unicode <= 128) {
				submissionScreen->addChar(static_cast<char>(event.text.unicode));
			}
		}
	}
}

void Game::render(sf::Time deltaTime) {
	window->clear(sf::Color::Black);
	switch (state) {
	case GAME:
		level->updateInternal(deltaTime.asSeconds());
		break;
	case MENU:
		menu->updateInternal(deltaTime.asSeconds());
		break;
	case SCORE_SUBMIT:
		submissionScreen->updateInternal(deltaTime.asSeconds());
		break;
	case SCORE_VIEW:
		scoreScreen->updateInternal(deltaTime.asSeconds());
		break;
	}
	window->display();
}

sf::RenderWindow *Game::getWindow() {
	return window;
}

Level *Game::getLevel() {
	return level;
}

ScoreSubmitter *Game::getScoreSubmitter() {
	return scoreSubmitter;
}

ScoreViewScreen *Game::getScoreViewScreen() {
	return scoreScreen;
}

void Game::transitionToGame() {
	initLevel();
	state = GAME;
}

void Game::transitionToMenu() {
	state = MENU;
}

void Game::transitionToScoreSubmit(int score) {
	state = SCORE_SUBMIT;
	submissionScreen->setScore(score);
}

void Game::transitiontoScoreView() {
	initScoreViewScreen();
	state = SCORE_VIEW;
}
