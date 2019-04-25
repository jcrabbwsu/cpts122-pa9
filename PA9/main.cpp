#pragma once

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

	//auto game = new Game();
	//game->run();

	//delete game;

	Test test5;

	test5.test5();

    return 0;
}
