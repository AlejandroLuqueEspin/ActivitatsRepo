#pragma once
#include "Bricks.h"
class NormalBrick :
	public Bricks
{
private:
	NormalBrick();
	std::string path;
public:
	void Damage();
	~NormalBrick();
};

