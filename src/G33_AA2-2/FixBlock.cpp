#include "FixBlock.h"



FixBlock::FixBlock()
{
}


FixBlock::~FixBlock()
{
}

FixBlock::FixBlock(Vec2 _blockPos, int _score)
{
	blockTextRect.h = blockTextRect.h / 3;
	blockTextRect.y = blockTextRect.h * 2;
	blockRect = Rect{ _blockPos.x, _blockPos.y, blockTextRect.w / 5, blockTextRect.h };
	blockCollision = { blockRect.x, blockRect.y - blockRect.h, blockRect.h, blockRect.w };
	points = _score;
	healthPoints = 1;
}


void FixBlock::Update()
{
	if (healthPoints == 0)
	{
		frameTime++;
		if (FPS / frameTime <= 9)
		{
			frameTime = 0;
			blockTextRect.x += blockRect.w;
			if (blockTextRect.x >= blockTextRect.w)
			{
				healthPoints = 1;
				blockTextRect.x = 0;
			}
		}
	}
}

void FixBlock::Draw(Renderer * myRenderer)
{

	myRenderer->PushRotatedSprite("Bricks", { blockTextRect.x, blockTextRect.y, blockRect.w, blockRect.h }, { blockRect.x, blockRect.y, blockRect.w, blockRect.h }, 90.0f);
}
