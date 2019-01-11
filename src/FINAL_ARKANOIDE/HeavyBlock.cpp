#include "HeavyBlock.h"



HeavyBlock::HeavyBlock()
{
}


HeavyBlock::~HeavyBlock()
{
}

HeavyBlock::HeavyBlock(Vec2 _blockPos, int _score)
{
	puedePower = true;
	blockTextRect.h = blockTextRect.h / 3;
	blockTextRect.y = blockTextRect.h;
	blockRect = Rect{_blockPos.x, _blockPos.y, blockTextRect.w / 5, blockTextRect.h };
	blockCollision = { blockRect.x, blockRect.y - blockRect.h, blockRect.h+10, blockRect.w };
	points = _score;
	healthPoints = 3;
}

void HeavyBlock::Update() 
{
	switch (healthPoints) {
	case 3:
		break;
		case 2:

			if (blockTextRect.x < blockRect.w) {
				frameTime++;
				if (FPS / frameTime <= 9)
				{
					frameTime = 0;
					blockTextRect.x += blockRect.w;
				}
			}
			break;
		case 1:
			if (blockTextRect.x <= blockRect.w) {
				frameTime++;
				if (FPS / frameTime <= 9)
				{
					frameTime = 0;
					blockTextRect.x += blockRect.w;
				}
			}
			break;
		default:
				frameTime++;
				if (FPS / frameTime <= 9)
				{
					frameTime = 0;
					blockTextRect.x += blockRect.w;
				}
				if (blockTextRect.x >= blockTextRect.w)
				{
					blockCollision = { NULL };
				}
			break;
	}
}

void HeavyBlock::Draw(Renderer* myRenderer)
{

	if (blockCollision.w != 0)myRenderer->PushRotatedSprite("Bricks", { blockTextRect.x, blockTextRect.y, blockRect.w, blockRect.h }, { blockRect.x, blockRect.y, blockRect.w, blockRect.h }, 90.0f);
}
