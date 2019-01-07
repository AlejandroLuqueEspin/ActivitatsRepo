#pragma once
#include "Types.h"
#include <iostream>
#include "Constants.h"
#include "Renderer.h"

class Block
{
protected:
	Rect blockRect;
	Rect blockTextRect;
public:
	Block();
	~Block();

	Rect blockCollision;
	int points;
	int healthPoints;
	float frameTime = 0;

	virtual void Update();
	virtual void Draw(Renderer* myRenderer);
};

