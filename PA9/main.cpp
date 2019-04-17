#include "Game.h"

/// <summary>
/// Entry point of the application
///  - Initializes the random seed.
///  - Creates the Game object.
///  - Start running the game.
/// </summary>
int main(void) {
	srand((unsigned int)time(NULL));

	auto game = new Game();
	game->run();

	delete game;

    return 0;
}
