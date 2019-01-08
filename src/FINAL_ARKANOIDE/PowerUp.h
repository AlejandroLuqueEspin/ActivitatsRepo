#pragma once
#include "Renderer.h"
#include "Types.h"
#include <cstdlib>

class PowerUp
{
	
	int powerUpDirection;
	float velocity=0.5;
	float lastTime, actualTime, TimeDown, deltaTime;

public:
	bool  owned;
	PowerUpPlayerState state = NULLE;
	Rect powerUpPosition;
	PowerUpType type;


	PowerUp();
	~PowerUp();

	PowerUp(PlayerNum lastPlayer, Vec2 _powerUpPos);
	void Update();
	void Draw(Renderer* myRenderer);
};

