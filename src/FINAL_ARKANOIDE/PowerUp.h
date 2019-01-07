#pragma once
#include "Renderer.h"
#include "Types.h"
#include <cstdlib>

class PowerUp
{
	bool death = false;
	int powerUpDirection;
	int velocity=1;
	PowerUpType type;
	float lastTime, actualTime, TimeDown, deltaTime;

public:
	
	Rect powerUpPosition;


	PowerUp();
	~PowerUp();

	PowerUp(PlayerNum lastPlayer, Vec2 _powerUpPos);
	void Update();
	void Draw(Renderer* myRenderer);
};

