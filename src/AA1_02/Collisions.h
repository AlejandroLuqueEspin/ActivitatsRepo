#pragma once
#include "tipos.h"
#include <iostream>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

inline namespace PlayerCollisions {
	bool ChecKCollision(Types::vec2 vec2, SDL_Rect rect) {

		if (vec2.x>rect.x&&vec2.y>rect.y&&vec2.x<rect.x+ rect.w&&vec2.y<rect.y+rect.h)
			return true;
		else
			return false;
	}
	bool CheckCollisionSprites(SDL_Rect sprite, SDL_Rect collision) {
		if ((sprite.x> collision.x&&sprite.y> collision.y&&sprite.x< collision.x+ collision.w&&sprite.y< collision.y+ collision.h))
			return true;
		else
			return false;
	}
	bool CheckCollisionCoin(SDL_Rect sprite, SDL_Rect coin) {
		if ((coin.x > sprite.x&&coin.y > sprite.y&&coin.x < sprite.x + sprite.w&&coin.y < sprite.y + sprite.h)) {
			return true;
		}
		else
			return false;
	}
}