#pragma once
#include "Types.h"
#include "Renderer.h"
class Ball
{
private:
	bool loaded = false;
public:
	Rect ballRect;
	Vec2 direction;
	int velocity;

	Ball();
	void UpdateMovement();
	void Draw(Renderer *myRenderer);
	void SetSpawn(Vec2 position);
	~Ball();
};

