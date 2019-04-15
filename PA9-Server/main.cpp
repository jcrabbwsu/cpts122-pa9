#include "Server.h"

int main() {
	auto server = new Server();
	server->listen();

	return 0;
}
