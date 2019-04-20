#pragma once

#include "GameObject.h"

class Entity : public GameObject {
public:
	Entity();
	~Entity();

	void init();
	void update(double deltaTime);
	virtual bool isOutOfBounds();
};