#include "Ranking.h"



void Ranking::LoadTextures(Renderer * myRenderer)
{
	//button textures
	myRenderer->LoadTextureText("SUNSPIRE", { "EXIT", "bEXIT_h", blue });
	myRenderer->LoadTextureText("SUNSPIRE", exitButton.text);

	//Background
	myRenderer->LoadTexture("RankingB", "../../res/img/apps.53029.9007199266525955.8c4385ac-fc48-4b5c-89e7-f1d71f13d5a4.jpg");//nombre y path
	loaded = true;
}

void Ranking::LoadScores()
{



}

Ranking::Ranking()
{
	exitButton= Button({ "EXIT", "bEXIT", yellow }, { (SCREEN_WIDTH / 3) + 50, (SCREEN_HEIGHT / 5) + 200, buttonSize.x, buttonSize.y }, "bEXIT", "bEXIT_h");

}


Ranking::~Ranking()
{
}

void Ranking::Update(Controller * inputs)
{
	if (exitButton.collision(inputs->mousePos) && inputs->mouse) sceneName = MENU;
}

void Ranking::Draw(Renderer * myRenderer)
{
	if (!loaded) LoadTextures(myRenderer);
	myRenderer->PushImage("RankingB", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	myRenderer->PushImage(exitButton.buttonId, { exitButton.bRect.x ,  exitButton.bRect.y,  exitButton.bRect.w,  exitButton.bRect.h });

}
