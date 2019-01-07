#pragma once
#include "Block.h"
class HeavyBlock :public Block
{
private:

public:
	HeavyBlock();
	HeavyBlock(Vec2 _blockPos, int _score);
	~HeavyBlock();

	void Update();
	void Draw(Renderer* myRenderer);
};

