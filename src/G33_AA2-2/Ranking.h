#pragma once
#include "Scene.h"
#include "Button.h"

class Ranking :	public Scene
{
	Button exitButton;

	void LoadTextures(Renderer* myRenderer);
	void LoadScores();

public:

	Ranking();
	~Ranking();

	void Update(Controller* inputs);
	void Draw(Renderer* myRenderer);
};

