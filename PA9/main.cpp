#pragma once

// Hey Andy, if you want to enable testing, uncomment this macro.
//#define TESTING

#include "Game.h"

#include "Menu.h"
#include "Test.h"

/// <summary>
/// Entry point of the application
///  - Initializes the random seed.
///  - Creates the Game object.
///  - Start running the game.
/// </summary>
int main(void) {
	srand((unsigned int)time(NULL));

#ifdef TESTING
	Test *test = new Test();

	test->test1();
	test->test2();
	test->test3();
	test->test4();
	test->test5();

	delete test;
#else
	auto game = new Game(false);
	game->run();

	delete game;
#endif

    return 0;
}
