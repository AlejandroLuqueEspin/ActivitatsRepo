#pragma once
#include "Utilities.h"
#include "Controller.h"
#include "Renderer.h"

class Scene
{
protected:
	bool loaded = false;
public:
	Scene();
	~Scene();
	virtual void Update(Controller* controller);
	virtual void Draw(Renderer* myRenderer);

	gameState sceneName;
};

