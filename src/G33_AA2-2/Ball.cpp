#include "Ball.h"



Ball::Ball()
{
	ballRect.w = ballRect.h = 18;
	direction = { 1, 1 };
	velocity = 2;
}

void Ball::UpdateMovement()
{
	ballRect.x +=direction.x   *velocity;
	ballRect.y +=direction.y * velocity;
}

void Ball::Draw(Renderer *myRenderer)
{
	if (!loaded) {
		myRenderer->LoadTexture("Ball", "../../res/img/ball.png");
		loaded = true;
	}
	myRenderer->PushImage("Ball", {ballRect.x, ballRect.y, ballRect.w, ballRect.h});
}

void Ball::SetSpawn(Vec2 position)
{
	ballRect.x = position.x- ballRect.w / 2;
	ballRect.y= position.y- ballRect.h / 2;
}

Ball::~Ball()
{
}
