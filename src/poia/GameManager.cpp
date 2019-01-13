#include "GameManager.h"



GameManager::GameManager()
{
	gameInputs = new Controller();
	actualScene = new SplashScreen();
	actualScene->sceneName = SPLASHSCREEN;
	lastScene = actualScene->sceneName;
}


GameManager::~GameManager()
{
}

void GameManager::Update(Renderer* myRenderer, bool &isRunning)
{
	gameInputs->Update();
	if (lastScene != actualScene->sceneName)
	{
		switch (actualScene->sceneName) {
		case MENU:
			delete actualScene;
			myRenderer->ClearScene();
			actualScene = new Menu();
			actualScene->sceneName = MENU;
			break;
		case PLAY:	
			delete actualScene;
			myRenderer->ClearScene();
			actualScene = new Game();
			actualScene->sceneName = PLAY;
			break;
		case SPLASHSCREEN:
			delete actualScene;
			myRenderer->ClearScene();
			actualScene = new SplashScreen();
			actualScene->sceneName = SPLASHSCREEN;
			break;
		case RANKING:
		{
			auxPuntuation = actualScene->newMaxPuntuation;
			auxName = actualScene->nameWinerPlayer;

			delete actualScene;
			myRenderer->ClearScene();
			actualScene = new Ranking();
			actualScene->sceneName = RANKING;
			if (lastScene == MENU) 
			{
				actualScene->LoadScores();
			}
			if (lastScene == PLAY) 
			{
				actualScene->nameWinerPlayer = auxName;
				actualScene->newMaxPuntuation = auxPuntuation;
				actualScene->UpdateScores();
				actualScene->LoadScores();
			}

		}
			break;
		default:
			isRunning = false;
			return;
		}
		lastScene = actualScene->sceneName;
	}

	actualScene->Update(gameInputs);
	actualScene->Draw(myRenderer);

	myRenderer->Render();
	myRenderer->Clear();
}
