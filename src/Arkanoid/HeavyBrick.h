#pragma once
#include "Bricks.h"
class HeavyBrick :
	public Bricks
{
private:
	std::string path;
public:
	HeavyBrick(std::string _path);
	HeavyBrick();
	void Damage();
	~HeavyBrick();
};

