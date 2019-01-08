#pragma once
#include "Renderer.h"
#include "Types.h"
#include <cstdlib>

class PowerUp
{
	
	int powerUpDirection;
	int velocity=1;
	float lastTime, actualTime, TimeDown, deltaTime;

public:
	bool activated, owned;
	Rect powerUpPosition;
	PowerUpType type;


	PowerUp();
	~PowerUp();

	PowerUp(PlayerNum lastPlayer, Vec2 _powerUpPos);
	void Update();
	void Draw(Renderer* myRenderer);
};

