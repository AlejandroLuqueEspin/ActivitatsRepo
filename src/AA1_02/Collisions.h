#pragma once
#include "tipos.h"

inline namespace PlayerCollisions {
	bool ChecKCollisionHover(Types::vec2 vec2, Types::myRect rect) {
		if (vec2.x<rect.x&&vec2.y<rect.y&&vec2.x>rect.w&&vec2.y>rect.h)
			return true;
		else
			return false;
	}
}