#pragma once
#include "Types.h"
#include <string>
class Bricks
{
private:

public:
	myRect BrickRect;
	int points;

	void Update();
	virtual void Damage();
	Bricks();
	Bricks(myRect Rect);
	~Bricks();
};

