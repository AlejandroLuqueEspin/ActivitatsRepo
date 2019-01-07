#pragma once
#include "Types.h"
#include "Controller.h"
#include "Renderer.h"


class Player
{
private:
	bool loaded = false;
	Vec2 playerVelocity;
	PlayerNum identifier;
public:
	Rect playerPos;
	Rect playerCollider;
	Text scoreText;
	int score;
	int livesLeft;
	int velocity;

	Player();
	Player(PlayerNum _num);
	int GetScore();
	void SetScore();
	void setPlayerRespawn();
	void Update(Controller* controller);
	void Draw(Renderer* myRenderer);
	~Player();
};

