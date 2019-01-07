#include "HUD.h"



HUD::HUD()
{
	scorePos1 = locationScoreP1;
	scorePos2 = locationScoreP2;
	points1 = new DinText(scorePos1);
	points2 = new DinText(scorePos2);
	lives1.push_back(locationLife1P1);
	lives1.push_back(locationLife2P1);
	lives1.push_back(locationLife3P1);
	lives2.push_back(locationLife1P2);
	lives2.push_back(locationLife2P2);
	lives2.push_back(locationLife3P2);
}


HUD::~HUD()
{
}


void HUD::Update(Text text1, Text text2)
{
	points1->UpdateText(text1);
	points2->UpdateText(text2);
}

void HUD::Draw(Renderer* myRenderer)
{


	points1->Draw(myRenderer);
	points2->Draw(myRenderer);
	
	for (auto a : lives1)
		myRenderer->PushImage("Platform", {a.x, a.y, a.w, a.h});
	for (auto a : lives2)
		myRenderer->PushImage("Platform", { a.x, a.y, a.w, a.h });

}
