#pragma once
#include "Bricks.h"
class HeavyBrick :
	public Bricks
{
private:
	HeavyBrick();
	std::string path;
public:
	void Damage();
	~HeavyBrick();
};

