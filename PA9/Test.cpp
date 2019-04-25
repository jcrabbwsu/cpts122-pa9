#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

void Test::test1()
{
}

void Test::test2()
{
}

void Test::test3()
{
}

void Test::test4()
{
}

void Test::test5()
{
	sf::Clock timer;
	sf::Time deltatime;

	Game* game = new Game;
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
