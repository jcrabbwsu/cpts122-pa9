#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

class Menu;
class Level;
class ScoreSubmissionScreen;
class ScoreSubmitter;
class ScoreViewScreen;

typedef enum {
	MENU,
	GAME,
	SCORE_SUBMIT,
	SCORE_VIEW
} state_t;

/// <summary>
/// Game is the 'root' object which manages the Level,
/// the sf::RenderWindow (including opening it, closing it, and events).
/// </summary>
class Game {
	sf::RenderWindow *window;
	Game *game;
	Menu *menu;
	Level *level;
	ScoreSubmissionScreen *submissionScreen;
	ScoreViewScreen *scoreScreen;
	ScoreSubmitter *scoreSubmitter;
	state_t state = MENU;

	void initLevel();
	void initSubmissionScreen();
	void initScoreViewScreen();

public:
	Game(bool testing);
	~Game();
	
	/// <summary>
	/// This function wraps the update loop into one function.
	/// It will calculate deltaTime, FPS, and also run the input(),
	/// and render(deltaTime) functions, which calls down to Level,
	/// using the initInternal and updateInternal functions.
	/// </summary>
	void run();

	/// <summary>
	/// Check for events from the Window and general input.
	/// </summary>
	void input();
	
	/// <summary>
	/// Calls down to Level, to run updateInternal(deltaTime).
	/// </summary>
	/// <param name="deltaTime">sf::Time for frame delta time.</param>
	void render(sf::Time deltaTime);

	/// <summary>
	/// Get a pointer to the sf::RenderWindow for this Game.
	/// </summary>
	/// <returns>Pointer for sf::RenderWindow</returns>
	sf::RenderWindow *getWindow();

	/// <summary>
	/// Get the pointer for the level of the game.
	/// </summary>
	/// <returns>Level pointer</returns>
	Level *getLevel();

	ScoreSubmitter *getScoreSubmitter();
	ScoreViewScreen *getScoreViewScreen();

	void transitionToGame();
	void transitionToMenu();
	void transitionToScoreSubmit(int score);
	void transitiontoScoreView();
};
