#pragma once
#include "tipos.h"

inline namespace PlayerCollisions {
	bool ChecKCollision(Types::vec2 vec2, SDL_Rect rect) {

		if (vec2.x>rect.x&&vec2.y>rect.y&&vec2.x<rect.x+ rect.w&&vec2.y<rect.y+rect.h)
			return true;
		else
			return false;
	}
}