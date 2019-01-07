#pragma once

#include <SDL.h>	
#include "Vec2.h"

enum class inputKeyboard { K_ESC, K_SPACE, K_UP, K_DOWN, K_W, K_S, K_P, QUIT, NUM_KEYS };
enum class inputMouse { LEFT_CLICK, NUM_KEYS };

class Controller
{
	SDL_Event event;
	//Scene gameScene;
public:
	Controller();
	~Controller();
	bool keyboard[(int)inputKeyboard::NUM_KEYS] = { false };
	bool mouse = false;
	Vec2 mousePos;
	gameState GameState;

	void Update();
};

