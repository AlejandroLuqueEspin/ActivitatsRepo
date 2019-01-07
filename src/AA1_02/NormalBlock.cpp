#include "NormalBlock.h"



NormalBlock::NormalBlock()
{
}


NormalBlock::~NormalBlock()
{
}

NormalBlock::NormalBlock(Vec2 _blockPos, int _score)
{
	
	blockTextRect.x = blockTextRect.y = 0;
	blockTextRect.h = blockTextRect.h / 3;
	
	blockRect = Rect{ _blockPos.x, _blockPos.y, blockTextRect.w / 5, blockTextRect.h };
	blockCollision = { blockRect.x, blockRect.y - blockRect.h, blockRect.h, blockRect.w };
	points = _score;
	healthPoints = 1;
}

void NormalBlock::Update() 
{
	if (healthPoints <= 0)
	{
		
		frameTime++;
		if (FPS / frameTime <= 9)
		{
			frameTime = 0;
			blockTextRect.x += blockRect.w;
			
			if (blockTextRect.x >= blockTextRect.w)
			{
				blockCollision = { NULL };
			}

		}
		
	}
}

void NormalBlock::Draw(Renderer* myRenderer)
{
	if (blockCollision.w != 0)myRenderer->PushRotatedSprite("Bricks", { blockTextRect.x, blockTextRect.y, blockRect.w, blockRect.h }, { blockRect.x, blockRect.y, blockRect.w, blockRect.h }, 90.0f);
}