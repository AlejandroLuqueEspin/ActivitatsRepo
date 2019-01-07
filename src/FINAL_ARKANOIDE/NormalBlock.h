#pragma once
#include "Block.h"
class NormalBlock :
	public Block
{
private:

public:
	NormalBlock();
	NormalBlock(Vec2 _blockPos, int _score);
	~NormalBlock();

	void Update();
	void Draw(Renderer* myRenderer);
};

