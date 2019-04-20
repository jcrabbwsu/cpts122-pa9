#pragma once

#include <SFML/Graphics.hpp>

class Game;

/// <summary>
/// GameObject is a 'wrapper' to allow for easy initialization,
/// updates, and deinitialization/cleanup of the object. GameObjects
/// can have child GameObjects. Level is implemented as a GameObject,
/// and the Player, Asteroids, and Aliens are all implemented as a GameObject,
/// as well as being children of the initial Level object.
/// </summary>
class GameObject {
	/// <summary>
	/// Whether or not this object is disposed.
	/// </summary>
	bool disposed = false;

	/// <summary>
	/// Pointer to the current game.
	/// </summary>
	Game *game;


public:
	/// <summary>
	/// Default constructor for GameObject.
	/// </summary>
	GameObject();

	/// <summary>
	/// Vector of pointers to children GameObjects.
	/// </summary>
	std::vector<GameObject *> children;

	std::vector<GameObject *> addedChildren;

	/// <summary>
	/// Vector of pointers to temporary deleted children GameObjects.
	/// </summary>
	std::vector<GameObject *> deletedChildren;

	/// <summary>
	/// Default deconstructor for GameObject.
	/// </summary>
	~GameObject();

	/// <summary>
	/// This init function is called once and ONLY once
	/// when the GameObject is added as a child to another
	/// GameObject.
	/// </summary>
	virtual void init() = 0;

	/// <summary>
	/// This update function is called every frame.
	/// Logic like movement, physics, and other things
	/// that need to be done periodically should happen here.
	/// </summary>
	/// <param name="deltaTime">Time in seconds since last frame</param>
	virtual void update(double deltaTime) = 0;

	/// <summary>
	/// Internal init function, called only from Game and this class.
	/// </summary>
	void initInternal();

	//check if object is out of bounds and set mOutOfBounds to true if it is
	virtual bool isOutOfBounds() = 0;

	/// <summary>
	/// Internal update function called only from Game and this class.
	/// </summary>
	/// <param name="deltaTime"></param>
	void updateInternal(double deltaTime);

	/// <summary>
	/// Shortcut to drawing a Drawable object.
	/// </summary>
	/// <param name="drawable">Reference to Drawable object</param>
	void draw(sf::Drawable &drawable);

	/// <summary>
	/// Get a pointer to the current Game.
	/// </summary>
	/// <returns></returns>
	Game *getGame();

	/// <summary>
	/// Set the current Game pointer.
	/// </summary>
	/// <param name="game">Pointer to the Game</param>
	void setGame(Game *game);

	/// <summary>
	/// Add a child GameObject.
	/// </summary>
	/// <param name="gameObject">GameObject to add as a child</param>
	void addChildGameObject(GameObject *gameObject);

	/// <summary>
	/// Dispose of this GameObject.
	/// </summary>
	void dispose();

	/// <summary>
	/// Determines whether or not this GameObject is disposed.
	/// </summary>
	/// <returns>True if GameObject is disposed.</returns>
	bool isDisposed();

	std::vector<GameObject *> getIntersectingChildren(GameObject *gameObject);

	virtual sf::FloatRect getBounds() = 0;
};
