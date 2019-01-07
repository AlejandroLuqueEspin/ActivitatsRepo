#include "Collisions.h"



Collisions::Collisions()
{
}

Ball Collisions::CheckCollisionBlock(std::vector<Rect> aux, Ball ball)//check a place where you will not collide so you can bounce without bugs
{
	bool collision = false;
	if (ball.direction == Vec2{ 1, 1 })
	{
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.x *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.y *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction * -1;
			return ball;
		}
	}
	else if (ball.direction == Vec2{ -1, 1 })
	{
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.x *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.y *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction * -1;
			else collision = true;
		}
		if (!collision)
		{
			ball.direction * -1;
			return ball;
		}
	}
	else if (ball.direction == Vec2{ -1, -1 })
	{
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.x *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.y *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction * -1;
			return ball;
		}
	}
	else if (ball.direction == Vec2{ 1, -1 })
	{
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.x *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if (!collision)
		{
			ball.direction.y *= -1;
			return ball;
		}
		collision = false;
		for (auto rect1 : aux)
		{
			if (!collision && CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) collision = true;
		}
		if(!collision)
		{
			ball.direction * -1;
			return ball;
		}
	}
	return ball;
}

bool Collisions::CheckRectWithRect(Rect rect1, Rect rect2)
{
	if ((rect1.x > rect2.x && rect1.y > rect2.y && rect1.x < rect2.x + rect2.w && rect1.y < rect2.y + rect2.h))
		return true;
	else
		return false;
}

ScreenLocation Collisions::CheckSideCollision(Rect rect1, Rect rect2)//check the side where the ball has been collided
{
	if (rect1.x < rect2.x )
		return LEFT;
	else if (rect1.x + rect1.w > rect2.x +rect2.w)
		return RIGHT;
	else if (rect1.y  < rect2.y )
		return UP ;
	else if (rect1.y + rect1.h > rect2.y+rect2.h )
		return DOWN;
	return (ScreenLocation)4;
}

Ball Collisions::CheckCollisionRectBall(Rect rect1, Ball ball)
{
	if (ball.direction == Vec2{ 1, 1 })
	{
		if (!CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.x *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.y *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction * -1;		
	}
	else if (ball.direction == Vec2{ -1, 1 })
	{
		if (!CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.x *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.y *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction * -1;
	}
	else if (ball.direction == Vec2{ -1, -1 })
	{
		if (!CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.x *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.y *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction * -1;
	}
	else if (ball.direction == Vec2{ 1, -1 })
	{
		if (!CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y - (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.x *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x + (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction.y *= -1;
		else if (!CheckRectWithRect({ ball.ballRect.x - (int)ball.velocity, ball.ballRect.y + (int)ball.velocity, ball.ballRect.w, ball.ballRect.h }, rect1)) ball.direction * -1;
	}
	return ball;
}//same has before but lower version


Collisions::~Collisions()
{
}
