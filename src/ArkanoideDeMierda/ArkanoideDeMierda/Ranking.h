#pragma once
#include "Scene.h"
#include "Button.h"
#include <algorithm>

class Ranking :	public Scene
{
	Button exitButton;

	std::map<std::string, int> ranking;
	void LoadTextures(Renderer* myRenderer);
	void UpdateScores();
	void LoadScores();
	bool loadedR = true;

public:

	Ranking();
	~Ranking();

	void Update(Controller* inputs);
	void Draw(Renderer* myRenderer);
};

