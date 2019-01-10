#include "Ball.h"



Ball::Ball()
{
}

void Ball::MoveBall()
{
	direction.x += speed;
	direction.y += speed;
}

void Ball::Draw(Renderer *myRenderer)
{
	myRenderer->PushImage(ball.ID, {ballRect.x, ballRect.y, ballRect.w, ballRect.h});
}

void Ball::SetBallPosition(Vec2 &map)
{
	map.x = direction.x;
	map.y = direction.y;
}

Ball::~Ball()
{
}
