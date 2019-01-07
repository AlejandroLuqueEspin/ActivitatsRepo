#include "SplashScreen.h"



SplashScreen::SplashScreen()
{
	myRect = { 0, 0, 1920, 1080 };
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::ShowSplashScreen() {
	lastTime = clock();
	actualTime = (lastTime / 1000) - 1;
	TimeDown = 60;
	deltaTime = 0;
}

void SplashScreen::Update(Controller *gameInputs)
{
	deltaTime = clock() - lastTime;
	lastTime = clock();
	deltaTime /= CLOCKS_PER_SEC;
	TimeDown -= deltaTime; 
	actualTime = (lastTime / 1000) - 1;
	if(actualTime>=3)
		sceneName = MENU;
}

void SplashScreen::Draw(Renderer *myRenderer)
{
	if (!loaded) {
		myRenderer->LoadTexture("Splash", "../../res/img/099-LOGO-ENTI-UB-H.jpg");
		loaded = true;
	}
	myRenderer->PushImage("Splash", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
}
