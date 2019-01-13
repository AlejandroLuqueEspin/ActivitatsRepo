#pragma once
#include "Utilities.h"
#include "Controller.h"
#include "Renderer.h"

class Scene
{
protected:
	bool loaded = false;
public:
	int newMaxPuntuation;
	std::string nameWinerPlayer;

	Scene();
	~Scene();
	virtual void Update(Controller* controller);
	virtual void Draw(Renderer* myRenderer);

	gameState sceneName;
};

