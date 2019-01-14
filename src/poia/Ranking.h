#pragma once
#include "Scene.h"
#include "Button.h"
#include <algorithm>


class Ranking :	public Scene
{
private:
	Button exitButton;

	std::vector<std::pair<int, std::string>> aRanking;
	void LoadTextures(Renderer* myRenderer);
	void LoadTexturesR(Renderer * myRenderer);
	bool sortbysec(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b);
	void SortScores();
	bool loadedR = true;
public:
	Ranking();
	~Ranking();
	void UpdateScores();
	void LoadScores();
	void Update(Controller* inputs);
	void Draw(Renderer* myRenderer);
};

