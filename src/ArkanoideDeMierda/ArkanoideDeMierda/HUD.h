#pragma once
#include <vector>
#include "DinText.h"
#include "Types.h"
#include "Renderer.h"

class HUD
{
private:

	Rect scorePos1, scorePos2;

public:
	std::vector<Rect> lives1, lives2;
	DinText *points1, *points2;

	HUD();
	~HUD();

	void Update(Text text1, Text text2);
	void Draw(Renderer* myRenderer);
};

