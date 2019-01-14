#pragma once
#include <vector>
#include "DynamicText.h"
#include "Types.h"
#include "Renderer.h"

class HUD
{
private:

	Rect scorePos1, scorePos2;

public:
	std::vector<Rect> lives1, lives2;
	DynamicText *points1, *points2;

	HUD();
	~HUD();

	void Update(Text text1, Text text2);
	void Draw(Renderer* myRenderer);
};

