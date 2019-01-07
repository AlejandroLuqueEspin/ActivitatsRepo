#pragma once
#include "Types.h"
#include "Renderer.h"

class DinText
{
	Text text;
	Rect position;
public:
	DinText();
	DinText(Rect newPosition);
	~DinText();

	void UpdateText(Text newText);
	void Draw(Renderer* myRenderer);
};

