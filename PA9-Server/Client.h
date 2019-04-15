#pragma once

#include "Server.h"

#include <SFML/Network.hpp>

class Client {
	Server &server;
	sf::TcpSocket *socket;
	std::thread socketThread;
	bool connected = true;

public:
	Client(Server &server, sf::TcpSocket *socket);
	~Client();

	void receiveLoop();
	bool isConnected();
};
