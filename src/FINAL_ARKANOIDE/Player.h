#pragma once
#include "Types.h"
#include "Controller.h"
#include "Renderer.h"
#include "PowerUp.h"


class Player
{
private:
	bool loaded = false;
	Vec2 playerVelocity;
	PlayerNum identifier;
public:
	PowerUp* actualPower;
	Rect playerPos;
	Rect playerCollider;
	Text scoreText;
	int score;
	int livesLeft;
	int velocity;
	bool powerAction = false;


	Player();
	Player(PlayerNum _num);
	int GetScore();
	void SetScore();
	void setPlayerRespawn();
	void Update(Controller* controller);
	void Draw(Renderer* myRenderer);
	void CheckPowerLife();
	~Player();
};

