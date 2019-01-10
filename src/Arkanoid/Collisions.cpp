#include "Collisions.h"



Collisions::Collisions()
{
}

bool Collisions::CheckVec2WRect(Vec2 vec2, myRect rect)
{
	if (vec2.x > rect.x&&vec2.y > rect.y&&vec2.x < rect.x + rect.w&&vec2.y < rect.y + rect.h)
		return true;
	else
		return false;
}

bool Collisions::CheckRectWRect(myRect rect1, myRect rect2)
{
	if ((rect1.x > rect2.x && rect1.y > rect2.y && rect1.x < rect2.x + rect2.w && rect1.y < rect2.y + rect2.h))
		return true;
	else
		return false;
}


Collisions::~Collisions()
{
}
