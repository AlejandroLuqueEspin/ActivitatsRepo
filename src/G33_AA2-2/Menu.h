#pragma once
#include "Scene.h"
#include "Button.h"

class Menu : public Scene
{
	Button exitButton;
	Button rankingButton;
	Button playButton;
	Button soundButton;
	void loadTextures(Renderer* myRenderer);

	std::string bgDir;


public:
	Menu();
	~Menu();

	void Update(Controller* inputs);
	void Draw(Renderer* myRenderer);
};

