#pragma once
#include "Types.h"
#include "Renderer.h"
class Ball
{
private:
	myRect ballRect;
	Vec2 direction;
	float speed;
public:
	Ball();
	void MoveBall();
	void Draw(Renderer *myRenderer);
	void SetBallPosition(Vec2 &map);
	~Ball();
};

