#include "Button.h"

Button::Button(){}

Button::Button(Text _text, Rect _bRect, std::string _buttonIdNormal, std::string _buttonIdHover)
{
	text = _text;
	bRect = _bRect;
	buttonIdNormal = _buttonIdNormal;
	buttonIdHover = _buttonIdHover;
}


Button::~Button()
{
}

bool Button::collision(Vec2 mousePos) 
{
	if (mousePos.x >= bRect.x && mousePos.x <= bRect.x + bRect.w && mousePos.y >= bRect.y && mousePos.y <= bRect.y + bRect.h) {
		buttonId = buttonIdHover;
		return true;
	}
	buttonId = buttonIdNormal;
	return false;
}
