#include "NoneBlock.h"



NoneBlock::NoneBlock(){}

NoneBlock::NoneBlock(Vec2 _blockPos, int _score)
{
	blockCollision = { NULL };
	blockRect = Rect{ _blockPos.x, _blockPos.y, blockTextRect.w / 5, blockTextRect.h };
}


NoneBlock::~NoneBlock()
{
}
