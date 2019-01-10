#pragma once
#include "Types.h"
class Collisions
{
public:
	Collisions();
	bool CheckVec2WRect(Vec2 vec2, myRect rect);
	bool CheckRectWRect(myRect rect1, myRect rect2);
	~Collisions();

	
};




	


