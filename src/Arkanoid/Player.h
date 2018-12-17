#pragma once
#include "Types.h"

class Player
{
	int posX, posY, weight, height, points;
	PowerStates powerUp;



public:
	Player();
	~Player();

	void Update();
	void CheckCollision(int colPosX, int colPosY, int height, int weight);
	// Es el Game el que coje inpouts y hace update de las variables de player [void GetInputs();]
};

