#include "Client.h"

#include <iostream>
#include <fstream>
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
		nlohmann::json json;
		try {
			json = nlohmann::json::parse(str);
		} catch (std::exception e) {
			std::cerr << prefix << "Client sent invalid JSON" << std::endl;
			break;
		}

		std::string messageType = json["messageType"].get<std::string>();

		if (messageType == "fetchScores") {
			std::ifstream ifs("scores.json");
			nlohmann::json scores = nlohmann::json::parse(ifs);
			nlohmann::json rootScores = nlohmann::json::object();
			rootScores["messageType"] = "scores";
			rootScores["scores"] = scores;
			sendMessage(rootScores);
		} else if (messageType == "submitScore") {
			std::string initials = json["initials"].get<std::string>();
			int score = json["score"].get<int>();
			std::ifstream ifs("scores.json");
			nlohmann::json scores = nlohmann::json::parse(ifs);
			scores.push_back({
				{"initials", initials},
				{"score", score}
			});
			std::ofstream ofs("scores.json");
			ofs << scores.dump();
			ofs.close();
		}
	}

	connected = false;
	socket->disconnect();
	std::cout << prefix << "Disconnected" << std::endl;
}

bool Client::isConnected() {
	return connected;
}

void Client::sendMessage(nlohmann::json json) {
	std::string dumpedJson = json.dump();
	const char* dumpedJsonBytes = dumpedJson.c_str();
	socket->send(dumpedJsonBytes, strlen(dumpedJsonBytes));
}
