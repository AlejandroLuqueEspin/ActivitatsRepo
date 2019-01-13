#pragma once
#include "Vec2.h"
#include "Types.h"
#include <iostream>

class Button
{
public:
	Text text;
	Rect bRect;
	std::string buttonId;
private:
	std::string buttonIdNormal;
	std::string buttonIdHover;
public:
	
	Button();
	Button(Text _text, Rect _bRect, std::string _buttonIdNormal, std::string _buttonIdHover);
	~Button();

	bool collision(Vec2 mousePos);
};

