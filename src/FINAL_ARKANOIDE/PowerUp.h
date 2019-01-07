#pragma once
#include "Renderer.h"
#include "Types.h"
#include <cstdlib>

class PowerUp
{
	bool loaded = false;
	int powerUpDirection;
	PowerUpType type;

public:
	
	Rect powerUpPosition;



	PowerUp(PlayerNum lastPlayer, Vec2 _powerUpPos);
	~PowerUp();

	void Update();
	void Draw(Renderer* myRenderer);
};

