#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

//Hannah's attempt at test code --> you can blame her for this function
void Test::test1() {
	sf::Clock timer;
	sf::Time deltatime = timer.getElapsedTime();

	//set up test window
	Game* game = new Game(true);
	game->transitionToGame();

	game->getLevel()->spawnNewHostile();

	while (timer.getElapsedTime().asSeconds() < 10)
	{
		game->render(deltatime);
	}

	delete game;
}

void Test::test2() {
	sf::Clock timer;
	sf::Time deltatime = timer.getElapsedTime();

	Game* game = new Game(true);
	game->transitionToGame();

	game->getLevel()->setSpawnRateUFO(0);
	game->getLevel()->setAsteroidSpawnRate(0);

	while (timer.getElapsedTime().asSeconds() < 10) {
		game->getLevel()->addChildGameObject(new Asteroid());
		game->getLevel()->getScoreboard()->setLives(100);
		game->render(deltatime);
	}

	delete game;
}

void Test::test3() {
	sf::Clock timer;
	sf::Time deltatime = timer.getElapsedTime();

	Game* game = new Game(true);
	game->transitionToGame();

	game->getLevel()->setSpawnRateUFO(0);
	game->getLevel()->setAsteroidSpawnRate(0);

	while (timer.getElapsedTime().asSeconds() < 10) {
		game->getLevel()->addChildGameObject(new UFO());
		game->getLevel()->getScoreboard()->setLives(100);
		game->render(deltatime);
	}

	delete game;
}

void Test::test4() {
	sf::Clock timer;
	sf::Time deltatime = timer.getElapsedTime();

	Game* game = new Game(true);
	game->transitionToGame();

	game->getLevel()->setSpawnRateUFO(10000);
	game->getLevel()->setAsteroidSpawnRate(10000);

	while (timer.getElapsedTime().asSeconds() < 10) {
		game->getLevel()->addChildGameObject(new UFO());
		game->getLevel()->getScoreboard()->setLives(100);
		game->render(deltatime);
	}

	delete game;
}

void Test::test5() {
	sf::Clock timer;
	sf::Time deltatime;

	Game* game = new Game(true);
	game->transitionToGame();

	game->getLevel()->setSpawnRateUFO(200);

	while (timer.getElapsedTime().asSeconds() < 10)
	{
		std::cout << "Current UFO spawn rate: 200" << std::endl;
		game->render(deltatime);
		game->getLevel()->getScoreboard()->setLives(1);
	}

	game->getLevel()->setSpawnRateUFO(100);

	while (timer.getElapsedTime().asSeconds() < 20)
	{
		std::cout << "Current UFO spawn rate: 100" << std::endl;
		game->getLevel()->getScoreboard()->setLives(100);
		game->render(deltatime);
	}

	game->getLevel()->setSpawnRateUFO(50);

	while (timer.getElapsedTime().asSeconds() < 30)
	{
		std::cout << "Current UFO spawn rate: 50" << std::endl;
		game->getLevel()->getScoreboard()->setLives(100);
		game->render(deltatime);
	}

	game->getLevel()->setSpawnRateUFO(10);

	while (timer.getElapsedTime().asSeconds() < 40)
	{
		std::cout << "Current UFO spawn rate: 10" << std::endl;
		game->getLevel()->getScoreboard()->setLives(100);
		game->render(deltatime);
	}
	
	delete game;
}
