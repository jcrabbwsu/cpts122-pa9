#include "Server.h"

#include "Client.h"

#include <iostream>

Server::Server() : tickThread(std::thread(&Server::tick, this)) {
}

Server::~Server() {
}

void Server::tick() {
	while (running) {
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}

void Server::listen() {
	sf::Socket::Status status = tcpListener.listen(port);
	if (status != sf::Socket::Done) {
		std::cerr << "Failed to start listening on port " << port << std::endl;
		return;
	}
	std::cout << "Listening on port " << port << std::endl;

	while (running) {
		sf::TcpSocket *client = new sf::TcpSocket();
		sf::Socket::Status acceptStatus = tcpListener.accept(*client);
		if (acceptStatus != sf::Socket::Done) {
			std::cerr << "Failed to accept socket client" << std::endl;
			continue;
		}
		clients.push_back(new Client(*this, client));

		cleanUpClients();
	}
}

void Server::cleanUpClients() {
	for (int i = 0; i < clients.size(); i++) {
		auto client = clients[i];
		if (!client->isConnected()) {
			clients.erase(clients.begin() + i);
			delete client;
		}
	}
}
