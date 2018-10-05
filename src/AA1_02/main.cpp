#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "tipos.h"
#include "SDL_mixer.h"
#include "Collisions.h"
#include <exception>
#include <iostream>
#include <string>

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define W 350
#define H 189

int main(int, char*[])
{
	// --- INIT SDL ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw "No es pot inicialitzar SDL subsystems";

	// --- WINDOW ---
	SDL_Window *m_window{ SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) };
	if (m_window == nullptr)
		throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	SDL_Renderer *m_renderer{ SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) };
	if (m_renderer == nullptr)
		throw "No es pot inicialitzar SDL_Renderer";

	//-->SDL_Image 
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";

	//-->SDL_TTF
	if (TTF_Init() != 0)throw "No es pot inicialitzar SDL_ttf";

	//-->SDL_Mix
	const Uint8 mixFlags{MIX_INIT_MP3};
	if (!(Mix_Init(mixFlags)&mixFlags))throw "error init sdl mixer";


	// --- SPRITES ---
		//Background
	SDL_Texture* bgTexture{ IMG_LoadTexture(m_renderer, "../../res/img/bg.jpg") };
	if (bgTexture == nullptr) throw "Error: bgTexture init";
	SDL_Rect bgRect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

	//Player 
	SDL_Texture *playerTexture{ IMG_LoadTexture(m_renderer,"../../res/img/kintoun.png") };
	SDL_Rect playerRect{ 0,0,350,189 };
	//-->Animated Sprite ---
	
	// --- TEXT ---
	TTF_Font *font{ TTF_OpenFont("../../res/ttf/saiyan.ttf",80) };
	if (font == nullptr) throw "No es pot inicialitzar TTF_Font";
	SDL_Surface *tmpSurf;


	//*********************Title 
	tmpSurf = TTF_RenderText_Blended(font, "Myfirst SDL Game", SDL_Color{ 255,150,0,155 }) ;
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *titleTexture(SDL_CreateTextureFromSurface(m_renderer, tmpSurf));//	Color 1


	tmpSurf = { TTF_RenderText_Blended(font,"Myfirst SDL Game", SDL_Color{ 100,100,50,155 }) };
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *textureTitleHover{ SDL_CreateTextureFromSurface(m_renderer,tmpSurf) };// Color 2

	SDL_Rect textRectTitle{ 100,50,tmpSurf->w,tmpSurf->h }; //Location
	//

	//*********************Play 
	tmpSurf = TTF_RenderText_Blended(font, "Play", SDL_Color{ 255,150,0,155 });
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *playTexture(SDL_CreateTextureFromSurface(m_renderer, tmpSurf));//	Color 1


	tmpSurf = { TTF_RenderText_Blended(font,"Play", SDL_Color{ 100,100,50,155 }) };
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *texturePlayHover{ SDL_CreateTextureFromSurface(m_renderer,tmpSurf) };// Color 2

	SDL_Rect textRectPlay{ 100,150,tmpSurf->w,tmpSurf->h }; //Location
	//

	//***********************Exit 
	tmpSurf = TTF_RenderText_Blended(font, "Exit", SDL_Color{ 255,150,0,155 });
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *exitTexture(SDL_CreateTextureFromSurface(m_renderer, tmpSurf));//	Color 1


	tmpSurf = { TTF_RenderText_Blended(font,"Exit", SDL_Color{ 100,100,50,155 }) };
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *textureExitHover{ SDL_CreateTextureFromSurface(m_renderer,tmpSurf) };// Color 2

	SDL_Rect textRectExit{ 100,250,tmpSurf->w,tmpSurf->h }; //Location
	//

	//*********************Sound 
	SDL_Rect textRectSound{ 100,350,tmpSurf->w,tmpSurf->h }; //Location
	//*******************************Sound_off
	tmpSurf = TTF_RenderText_Blended(font, "Sound off", SDL_Color{ 255,150,0,155 });
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *soundOffTexture(SDL_CreateTextureFromSurface(m_renderer, tmpSurf));//	Color 1

	tmpSurf = { TTF_RenderText_Blended(font,"Sound off", SDL_Color{ 100,100,50,155 }) };
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *textureSoundOffHover{ SDL_CreateTextureFromSurface(m_renderer,tmpSurf) };// Color 2

	//******************************Sound_ON
	tmpSurf = TTF_RenderText_Blended(font, "Sound on", SDL_Color{ 255,150,0,155 });
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *soundOnTexture(SDL_CreateTextureFromSurface(m_renderer, tmpSurf));//	Color 1

	tmpSurf = { TTF_RenderText_Blended(font,"Sound on", SDL_Color{ 100,100,50,155 }) };
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *textureSoundOnHover{ SDL_CreateTextureFromSurface(m_renderer,tmpSurf) };// Color 2

	//

	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);

	SDL_Texture *textureAuxTitle,*textureAuxPlay,*textureAuxSound,*textureAuxExit;
	


	Types:: vec2 mousePos = { 0,0 };
	Types::myRect newRectTitle = { textRectTitle.x,textRectTitle.y,textRectTitle.w,textRectTitle.h };
	Types::myRect newRectPlay = { textRectPlay.x,textRectPlay.y,textRectPlay.w,textRectPlay.h };
	Types::myRect newRectSound = { textRectSound.x,textRectSound.y,textRectSound.w,textRectSound.h };
	Types::myRect newRectExit = { textRectExit.x,textRectExit.y,textRectExit.w,textRectExit.h };

	// --- AUDIO ---
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		throw "No es pot inicializar SLD_MIXER";

	Mix_Music *soundtrack(Mix_LoadMUS("../../res/au/mainTheme.mp3"));
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(soundtrack,-1);
	// --- GAME LOOP ---
	SDL_Event event;
	bool click = false;
	bool isRunning = true;

	while (isRunning) {
		// HANDLE EVENTS
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
				break;

			case SDL_MOUSEMOTION:
				int w, h;
				SDL_QueryTexture(playerTexture, NULL, NULL, &w, &h);

				playerRect.x = event.motion.x - W / 2;
				playerRect.y = event.motion.y - H / 2;

				//Actualiza la x e y
				mousePos.x = event.motion.x;
				mousePos.y = event.motion.y;
			case SDL_MOUSEBUTTONDOWN:
				click = true;
				break;

			default:;
			}
		}

		// ****************************************************************************************UPDATE
		textureAuxTitle = PlayerCollisions::ChecKCollision(mousePos, newRectTitle) ? textureTitleHover : titleTexture;
		textureAuxPlay = PlayerCollisions::ChecKCollision(mousePos, newRectPlay) ? texturePlayHover : playTexture;
		textureAuxExit = PlayerCollisions::ChecKCollision(mousePos, newRectExit) ? textureExitHover : exitTexture;
		if (Mix_PlayingMusic()) {
			if (!Mix_PausedMusic()) {
				textureAuxSound = PlayerCollisions::ChecKCollision(mousePos, newRectExit) ? textureSoundOnHover : soundOnTexture;
				if (click&&PlayerCollisions::ChecKCollision(mousePos, newRectSound))
					Mix_PauseMusic();
			}
			else {
				textureAuxSound = PlayerCollisions::ChecKCollision(mousePos, newRectExit) ? textureSoundOffHover : soundOffTexture;
				if (click&&PlayerCollisions::ChecKCollision(mousePos, newRectSound))
					Mix_ResumeMusic();
			}

		}
		else
			textureAuxSound = soundOffTexture;




		// ****************************************************************************************DRAW
		SDL_RenderClear(m_renderer);
		//Background
		SDL_RenderCopy(m_renderer, bgTexture, nullptr, &bgRect);
		//player
		SDL_RenderCopy(m_renderer, playerTexture, nullptr, &playerRect);

		//text
		//*********************************
		SDL_RenderCopy(m_renderer, textureAuxTitle, nullptr, &textRectTitle);//Title
		//*********************************
		//*********************************
		SDL_RenderCopy(m_renderer, textureAuxPlay, nullptr, &textRectPlay);//Play
		//*********************************
		//*********************************
		SDL_RenderCopy(m_renderer, textureAuxSound, nullptr, &textRectSound);//Sound
		//*********************************
		//*********************************
		SDL_RenderCopy(m_renderer, textureAuxExit, nullptr, &textRectExit);//exit
		//*********************************
		//

		SDL_RenderPresent(m_renderer);

	}

	// --- DESTROY ---
	/*SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(textureAuxTitle);
	SDL_DestroyTexture(textureAuxPlay);
	SDL_DestroyTexture(textureAuxSound);
	SDL_DestroyTexture(textureAuxExit);
	*/
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	// --- QUIT ---
	SDL_Quit();

	return 0;
}