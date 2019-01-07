#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Controller.h"
#include "Utilities.h"
#include "Menu.h"
#include "Game.h"
#include "SplashScreen.h"
#include "Ranking.h"

class GameManager
{
	gameState lastScene;
	Controller *gameInputs;
	Scene *actualScene;

public:
	GameManager();
	~GameManager();
	void Update(Renderer* myRenderer, bool &isRunning);
};

