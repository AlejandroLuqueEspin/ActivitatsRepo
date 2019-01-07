#pragma once
#include "Renderer.h"
#include "Types.h"
#include <cstdlib>

class PowerUp
{
	
	int powerUpDirection;
	int velocity=1;
	PowerUpType type;
	float lastTime, actualTime, TimeDown, deltaTime;

public:
	bool death = false;
	Rect powerUpPosition;


	PowerUp();
	~PowerUp();

	PowerUp(PlayerNum lastPlayer, Vec2 _powerUpPos);
	void Update();
	void Draw(Renderer* myRenderer);
};

