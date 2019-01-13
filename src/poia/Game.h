#pragma once
#include "Scene.h"
#include "Ball.h"
#include "Collisions.h"
#include "HUD.h"
#include "Player.h"
#include "Block.h"
#include "NormalBlock.h"
#include "FixBlock.h"
#include "HeavyBlock.h"
#include "NoneBlock.h"
#include "PowerUp.h"
#include <fstream>
#include <sstream>
#include <vector>
#include"SDL_mixer.h"

#include "Button.h"
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"


class Game : public Scene
{
	enum GameSceneState { START_GAME, RUNNING, PAUSED, GAME_OVER };
	Ball ball;
	Collisions collisions;
	Button soundButton;
	std::vector<PowerUp*> powerUpsVector;
	Player * player1, *player2;
	HUD hud;
	Block *mapBlock[12][11];
	PlayerNum lastPlayerCollision;
	GameSceneState sceneState;
	float pauseTime, reanudeTime;
	bool spacePressed;
	void loadSettings(Renderer* myRenderer);
	std::vector<Rect>neighboringBlocks;
	void getNeighbourBlocks(int i, int j);
public:

	Game();
	~Game();
	void Update(Controller * inputs);
	void Draw(Renderer* myRenderer);
};

