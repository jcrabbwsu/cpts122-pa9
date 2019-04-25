#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

//Hannah's attempt at test code --> you can blame her for this function
void Test::test1()
{
	////set up test window
	//sf::RenderWindow testWindow (sf::VideoMode(1200, 800), "AsteroidsTest");

	////keep window open until user closes it
	//while (testWindow.isOpen())
	//{
	//	sf::Event event;
	//	while (testWindow.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			testWindow.close();
	//	}

	//	Asteroid testAsteroid();

	//	testWindow.draw(testAsteroid);
	//}

	sf::Clock timer;
	sf::Time deltatime;
	new Asteroid();

	//set up test window
	Game* game = new Game;
	game->transitionToGame();

	game->getLevel()->spawnNewHostile();

	while (timer.getElapsedTime().asSeconds() < 10)
	{
	game->render(deltatime);

	}
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
