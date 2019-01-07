#include "Controller.h"



Controller::Controller()
{
	mousePos = Vec2(event.motion.x, event.motion.y);
	GameState = SPLASHSCREEN;
}


Controller::~Controller()
{
}

void Controller::Update() {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			keyboard[(int)inputKeyboard::QUIT] = true;
			break;
		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_ESCAPE) keyboard[(int)inputKeyboard::K_ESC] = true;
			if (event.key.keysym.sym == SDLK_SPACE) keyboard[(int)inputKeyboard::K_SPACE] = true;
			if (event.key.keysym.sym == SDLK_w) keyboard[(int)inputKeyboard::K_W] = true;
			if (event.key.keysym.sym == SDLK_s) keyboard[(int)inputKeyboard::K_S] = true;
			if (event.key.keysym.sym == SDLK_p) keyboard[(int)inputKeyboard::K_P] = true;
			if (event.key.keysym.sym == SDLK_UP) keyboard[(int)inputKeyboard::K_UP] = true;
			if (event.key.keysym.sym == SDLK_DOWN) keyboard[(int)inputKeyboard::K_DOWN] = true;
		}
		break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_ESCAPE) keyboard[(int)inputKeyboard::K_ESC] = false;
			if (event.key.keysym.sym == SDLK_SPACE) keyboard[(int)inputKeyboard::K_SPACE] = false;
			if (event.key.keysym.sym == SDLK_w) keyboard[(int)inputKeyboard::K_W] = false;
			if (event.key.keysym.sym == SDLK_s) keyboard[(int)inputKeyboard::K_S] = false;
			if (event.key.keysym.sym == SDLK_p) keyboard[(int)inputKeyboard::K_P] = false;
			if (event.key.keysym.sym == SDLK_UP) keyboard[(int)inputKeyboard::K_UP] = false;
			if (event.key.keysym.sym == SDLK_DOWN) keyboard[(int)inputKeyboard::K_DOWN] = false;
			break;
		case SDL_MOUSEMOTION:
			mousePos.x = event.motion.x;
			mousePos.y = event.motion.y;
			break;
		case SDL_MOUSEBUTTONDOWN:
			mouse = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mouse = false;
			break;

		default:;
		}
	}
}
