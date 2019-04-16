#include "Game.h"

int main(void) {
	srand((unsigned int)time(NULL));

	auto game = new Game();
	game->run();

    return 0;
}
