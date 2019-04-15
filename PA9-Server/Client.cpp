#include "Client.h"

#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>

Client::Client(Server &server, sf::TcpSocket *socket)
	: server(server)
	, socket(socket)
	, socketThread(&Client::receiveLoop, this) {
}

Client::~Client() {
	socketThread.join();
	delete socket;
}

void Client::receiveLoop() {
	std::cout << socket->getRemoteAddress() << " has connected" << std::endl;
	std::ostringstream prefixStream;
	prefixStream << "[" << socket->getRemoteAddress() << ":" << socket->getRemotePort() << "] ";
	std::string prefix = prefixStream.str();

#define BUFFER_SIZE 8192
	char buffer[BUFFER_SIZE];
	std::size_t receivedSize;

	while (true) {
		sf::Socket::Status status = socket->receive(buffer, BUFFER_SIZE, receivedSize);
		if (status != sf::Socket::Done) {
			std::cerr << prefix << "Socket failure on receive" << std::endl;
			break;
		}

		std::string str(reinterpret_cast<char const *>(buffer), receivedSize);
		std::cout << prefix << "Received: " << str << std::endl;
		try {
			nlohmann::json json = nlohmann::json::parse(str);
		} catch (std::exception e) {
			std::cerr << prefix << "Client sent invalid JSON" << std::endl;
			break;
		}
	}

	connected = false;
	socket->disconnect();
	std::cout << prefix << "Disconnected" << std::endl;
}

bool Client::isConnected() {
	return connected;
}
