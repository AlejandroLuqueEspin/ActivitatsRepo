#pragma once
#include "Block.h"
class NoneBlock : public Block
{
public:
	NoneBlock();
	NoneBlock(Vec2 _blockPos, int _score);
	~NoneBlock();
};

