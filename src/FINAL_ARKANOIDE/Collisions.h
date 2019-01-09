#pragma once
#include "Types.h"
#include "Ball.h"
#include "Block.h"

class Collisions
{
public:
	Collisions();

	bool CheckRectWithRect(Rect rect1, Rect rect2);
	bool CheckPlayerPowerUps(Rect rect1, Rect rect2);
	ScreenLocation CheckSideCollision(Rect rect1, Rect rect2);
	Ball CheckCollisionRectBall(Rect rect1, Ball ball);
	Ball CheckCollisionBlock(std::vector<Rect> aux, Ball ball);
	~Collisions();

	
};




	


