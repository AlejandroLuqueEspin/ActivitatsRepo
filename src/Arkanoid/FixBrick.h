#pragma once
#include "Bricks.h"
class FixBrick :
	public Bricks
{
private:
	FixBrick();
	std::string path;

public:
	void Damage();
	~FixBrick();
};

