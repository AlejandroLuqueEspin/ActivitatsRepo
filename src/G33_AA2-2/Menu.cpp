#include "Menu.h"



void Menu::loadTextures(Renderer* myRenderer)
{
	myRenderer->LoadTextureText("SUNSPIRE", { "PLAY", "bPLAY_h", red });
	myRenderer->LoadTextureText("SUNSPIRE", { "EXIT", "bEXIT_h", blue });
	myRenderer->LoadTextureText("SUNSPIRE", { "RANKING", "bRANKING_h", yellow });
	myRenderer->LoadTextureText("SUNSPIRE", { "SOUND", "bSOUND_h", green });
	myRenderer->LoadTextureText("SUNSPIRE", playButton.text);
	myRenderer->LoadTextureText("SUNSPIRE", exitButton.text);
	myRenderer->LoadTextureText("SUNSPIRE", rankingButton.text);
	myRenderer->LoadTextureText("SUNSPIRE", soundButton.text);

	myRenderer->LoadTexture("MenuB", "../../res/img/39876678-new-future-technology-concept-abstract-background-for-business-solution.jpg");

	loaded = true;
}

Menu::Menu()
{
	playButton = Button({ "PLAY", "bPLAY", green }, { (SCREEN_WIDTH / 3)+50, (SCREEN_HEIGHT / 5)-100, buttonSize.x, buttonSize.y}, "bPLAY", "bPLAY_h");
	exitButton = Button({ "EXIT", "bEXIT", yellow }, { (SCREEN_WIDTH / 3)+ 50, (SCREEN_HEIGHT / 5), buttonSize.x, buttonSize.y}, "bEXIT", "bEXIT_h");
	rankingButton = Button({ "RANKING", "bRANKING", blue }, { (SCREEN_WIDTH / 3)+ 50, (SCREEN_HEIGHT / 5)+100, buttonSize.x, buttonSize.y }, "bRANKING", "bRANKING_h");
	soundButton = Button({ "SOUND", "bSOUND", red }, { (SCREEN_WIDTH / 3)+ 50, (SCREEN_HEIGHT / 5)+200, buttonSize.x, buttonSize.y }, "bSOUND", "bSOUND_h");
}


Menu::~Menu()
{
}

void Menu::Update(Controller* inputs)
{
	if (exitButton.collision(inputs->mousePos) && inputs->mouse) sceneName = (gameState)10;
	if (rankingButton.collision(inputs->mousePos)) {
		//HOVER
		if (inputs->mouse); //RANKING
	}
	if (playButton.collision(inputs->mousePos) && inputs->mouse) sceneName = PLAY;
	if (soundButton.collision(inputs->mousePos)) {
		//HOVER
		if (inputs->mouse); //PLAY
	}
}

void Menu::Draw(Renderer* myRenderer)
{
	if (!loaded) loadTextures(myRenderer);
	myRenderer->PushImage("MenuB", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	myRenderer->PushImage(playButton.buttonId, { playButton.bRect.x ,  playButton.bRect.y,  playButton.bRect.w,  playButton.bRect.h });
	myRenderer->PushImage(exitButton.buttonId, { exitButton.bRect.x ,  exitButton.bRect.y,  exitButton.bRect.w,  exitButton.bRect.h });
	myRenderer->PushImage(rankingButton.buttonId, { rankingButton.bRect.x ,  rankingButton.bRect.y,  rankingButton.bRect.w,  rankingButton.bRect.h });
	myRenderer->PushImage(soundButton.buttonId, { soundButton.bRect.x ,  soundButton.bRect.y,  soundButton.bRect.w,  soundButton.bRect.h });

}
