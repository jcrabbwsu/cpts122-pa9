#pragma once

#include <vector>
#include <SFML/Network.hpp>
#include <nlohmann/json.hpp>
#include <thread>

class Game;

typedef struct {
	std::string initials;
	int score;
} score_t;

class ScoreSubmitter {
	sf::TcpSocket socket;
	std::thread socketThread;
	Game *game;

public:
	ScoreSubmitter(Game *game, bool testing);
	~ScoreSubmitter();

	void submitScore(std::string initials, int score);
	void getScores();

	void receiveLoop();
	void sendMessage(nlohmann::json json);
};
