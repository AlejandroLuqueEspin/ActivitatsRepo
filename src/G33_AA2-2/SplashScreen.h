#pragma once
#include "Scene.h"
#include "Vec2.h"
#include "Types.h"
#include "Constants.h"

class SplashScreen : public Scene
{
	int textWidth, textHeight, frameWidth, frameHeight;
	int spritesX, spritesY;
	float time;
	float frameTime = 0, lastTimeRef = 0;
	float deltaTime, TimeDown, actualTime;
	clock_t lastTime;
public:
	std::string splashDir;
	Rect myRect;
	SplashScreen();
	~SplashScreen();
	void ShowSplashScreen();
	void Update(Controller *gameInputs);
	void Draw(Renderer *myRenderer);

};

