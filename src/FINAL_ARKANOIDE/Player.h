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
	float velocity;
	float auxVelocity; //esta velocidad será guardada para hacer los calculos y añadirselos a verdadera velocidad
	bool powerAction = false;


	Player();
	Player(PlayerNum _num);
	int GetScore();
	void SetScore();
	void setPlayerRespawn();
	void Update(Controller* controller);
	void Draw(Renderer* myRenderer);
	void SumarPowerUps();
	void RestarPoweUps();
	void ReiniciarPowers();
	~Player();
};

