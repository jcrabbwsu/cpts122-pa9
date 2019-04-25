#include "ScoreSubmitter.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

#include "Game.h"
#include "ScoreViewScreen.h"

ScoreSubmitter::ScoreSubmitter(Game *game, bool testing) : game(game) {
	if (!testing) {
		socket.connect("apartment.gorence.xyz", 1612);
		socketThread = std::thread(&ScoreSubmitter::receiveLoop, this);
	}
}

ScoreSubmitter::~ScoreSubmitter() {
	socketThread.join();
}

void ScoreSubmitter::submitScore(std::string initials, int score) {
	nlohmann::json json;
	json["messageType"] = "submitScore";
	json["score"] = score;
	json["initials"] = initials;

	sendMessage(json);
}

void ScoreSubmitter::getScores() {
	nlohmann::json json;
	json["messageType"] = "fetchScores";

	sendMessage(json);
}

void ScoreSubmitter::receiveLoop() {
	std::cout << "connected to: " << socket.getRemoteAddress() << std::endl;
	std::ostringstream prefixStream;
	prefixStream << "[" << socket.getRemoteAddress() << ":" << socket.getRemotePort() << "] ";
	std::string prefix = prefixStream.str();

#define BUFFER_SIZE 8192
	char buffer[BUFFER_SIZE];
	std::size_t receivedSize;

	while (true) {
		sf::Socket::Status status = socket.receive(buffer, BUFFER_SIZE, receivedSize);
		if (status != sf::Socket::Done) {
			std::cerr << prefix << "Socket failure on receive" << std::endl;
			break;
		}

		std::string str(reinterpret_cast<char const *>(buffer), receivedSize);
		std::cout << prefix << "Received: " << str << std::endl;
		nlohmann::json json;
		try {
			json = nlohmann::json::parse(str);
		}
		catch (std::exception e) {
			std::cerr << prefix << "Client sent invalid JSON" << std::endl;
			break;
		}

		std::string messageType = json["messageType"].get<std::string>();

		if (messageType == "scores") {
			std::vector<score_t> scores;
			for (auto entry : json["scores"]) {
				std::string initials = entry["initials"].get<std::string>();
				int score = entry["score"].get<int>();
				score_t scoreEntry = {
				};
				scoreEntry.initials = initials;
				scoreEntry.score = score;
				scores.push_back(scoreEntry);
			}
			game->getScoreViewScreen()->setScores(scores);
		}
	}

	socket.disconnect();
	std::cout << prefix << "Disconnected" << std::endl;
}

void ScoreSubmitter::sendMessage(nlohmann::json json) {
	std::string dumpedJson = json.dump();
	const char* dumpedJsonBytes = dumpedJson.c_str();
	socket.send(dumpedJsonBytes, strlen(dumpedJsonBytes));
}
