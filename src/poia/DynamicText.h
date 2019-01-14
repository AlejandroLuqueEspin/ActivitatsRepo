#pragma once
#include "Types.h"
#include "Renderer.h"

class DynamicText
{
	Text text;
	Rect position;
public:
	DynamicText();
	DynamicText(Rect newPosition);
	~DynamicText();

	void UpdateText(Text newText);
	void Draw(Renderer* myRenderer);
};

