#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

class Level;

/// <summary>
/// Game is the 'root' object which manages the Level,
/// the sf::RenderWindow (including opening it, closing it, and events).
/// </summary>
class Game {
	sf::RenderWindow *window;
	Level *level;

public:
	Game();
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
};
