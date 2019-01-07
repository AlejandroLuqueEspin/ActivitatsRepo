#pragma once
#include "Block.h"
class FixBlock :public Block
{
private:

public:
	FixBlock();
	FixBlock(Vec2 _blockPos, int _score);
	~FixBlock();

	void Update();
	void Draw(Renderer* myRenderer);
};

