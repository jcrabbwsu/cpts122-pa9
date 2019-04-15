#pragma once

class Client;

#include <SFML/Network.hpp>

#include <thread>

class Server {
	const unsigned short port = 1612;
	bool running = true;
	std::thread tickThread;
	sf::TcpListener tcpListener;
	std::vector<Client *> clients;

public:
	Server();
	~Server();

	void tick();
	void listen();
	void cleanUpClients();
};
