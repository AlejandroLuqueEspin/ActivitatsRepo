#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "tipos.h"
#include "SDL_mixer.h"
#include "Collisions.h"
#include <exception>
#include <iostream>
#include <string>
#include<time.h>

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define W 350
#define H 189

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

void IncPoints(int frameTimeAnimNum, SDL_Rect numSpriteRect,SDL_Rect numSpriteRect2, int frameWidthNum)
{
	numSpriteRect.x += frameWidthNum;
	frameTimeAnimNum++;

	if (frameTimeAnimNum > 10) {
		frameTimeAnimNum = 0;
		numSpriteRect.x = 0;
		numSpriteRect2.x += frameWidthNum;
	}
}

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

	//------------------------------------BackgroundCatle
	SDL_Texture* bgCastleTexture{ IMG_LoadTexture(m_renderer, "../../res/img/bgCastle.jpg") };
	if (bgCastleTexture == nullptr) throw "Error: bgTexture init";
	SDL_Rect bgCastleRect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

	//--------------------------------------Player 
	SDL_Texture *playerTexture{ IMG_LoadTexture(m_renderer,"../../res/img/kintoun.png") };
	SDL_Rect playerRect{ 0,0,350,189 };
	int w, h;


	//---------------------------------->Animated Sprite ---
	//*****************MAIN CHARACHTER
	SDL_Texture *playerAnimTexture{ IMG_LoadTexture(m_renderer,"../../res/img/sp01.png") };
	if (bgCastleTexture == nullptr) throw "Error: playerAnimText init";

	SDL_Rect playerAnimRect, playerAnimPosition;
	int textWidth, textHeight, frameWidth, frameHeight;
	SDL_QueryTexture(playerAnimTexture, NULL, NULL, &textWidth, &textHeight);
	
	frameWidth = textWidth / 6;
	frameHeight = textHeight / 1;

	playerAnimPosition.x = playerAnimPosition.y = 200;
	playerAnimRect.x = playerAnimRect.y = 0;

	playerAnimPosition.h = 90; //size of position of the sprite
	playerAnimPosition.w = 90;

	playerAnimRect.h = frameHeight;//size of animation rect, equal to the frame of the png
	playerAnimRect.w = frameWidth;

	int frameTimeAnim=0;

	//*****************SECOND CHARACHTER
	SDL_Rect  playerAnimPosition2;
	playerAnimPosition2.x = playerAnimPosition2.y = 300;

	playerAnimPosition2.h = 90; //size of position of the sprite
	playerAnimPosition2.w = 90;

	
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

	SDL_Rect textRectTitle{ 100,50,SCREEN_WIDTH/2,100 }; //Location
	//

	//*********************Play 
	tmpSurf = TTF_RenderText_Blended(font, "Play", SDL_Color{ 255,150,0,155 });
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *playTexture(SDL_CreateTextureFromSurface(m_renderer, tmpSurf));//	Color 1


	tmpSurf = { TTF_RenderText_Blended(font,"Play", SDL_Color{ 100,100,50,155 }) };
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *texturePlayHover{ SDL_CreateTextureFromSurface(m_renderer,tmpSurf) };// Color 2


	SDL_Rect textRectPlay={ 50,150,200,100 }; //Location
	//

	//***********************Exit 
	tmpSurf = TTF_RenderText_Blended(font, "Exit", SDL_Color{ 255,150,0,155 });
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *exitTexture(SDL_CreateTextureFromSurface(m_renderer, tmpSurf));//	Color 1


	tmpSurf = { TTF_RenderText_Blended(font,"Exit", SDL_Color{ 100,100,50,155 }) };
	if (tmpSurf == nullptr)throw "No es pot crear SDL Surface";
	SDL_Texture *textureExitHover{ SDL_CreateTextureFromSurface(m_renderer,tmpSurf) };// Color 2

	SDL_Rect textRectExit={ 50,250,200,100 }; //Location
	//

	//*********************Sound 
	SDL_Rect textRectSound={ 50,350,200,100 }; //Location
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
	textureAuxExit = textureAuxPlay = textureAuxSound = textureAuxTitle = nullptr;
	
	Types:: vec2 mousePos = { 0,0 };

	// --- AUDIO ---
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		throw "No es pot inicializar SLD_MIXER";

	Mix_Music *soundtrack(Mix_LoadMUS("../../res/au/mainTheme.mp3"));
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(soundtrack,-1);

	//--- TIME ---
	Uint32 frameStart, frameTime,actualTime,startTime;
	clock_t lastTime = clock();
	float deltaTime, timeDown;
	timeDown = 60;
	deltaTime = 0;

	std::string timeDisplayable;
	SDL_Surface *timeDisplay{ TTF_RenderText_Blended(font,timeDisplayable.c_str(),SDL_Color {255, 255, 255}) };
	SDL_Texture *texturePoints{ SDL_CreateTextureFromSurface(m_renderer,timeDisplay) };
	SDL_Rect pointsRect { SCREEN_WIDTH / 2,0,SCREEN_WIDTH / 6,SCREEN_WIDTH / 6 };
	//----------------------------------------Collisions---------------------------
	//--------------------------------------Sky
	SDL_Rect skyRect{ 0,0,SCREEN_WIDTH ,SCREEN_HEIGHT / 5 };


	//--------------------------------------WindowLeft
	SDL_Rect windowLeft{ 0,0,10 ,SCREEN_HEIGHT };
	//--------------------------------------WindowRight
	SDL_Rect windowRight{ SCREEN_WIDTH - playerAnimPosition.w,0,10,SCREEN_HEIGHT };
	//--------------------------------------WindowDown
	SDL_Rect windowDown{ 0,SCREEN_HEIGHT - playerAnimPosition.h,SCREEN_WIDTH ,200 };


	//-------------------------------------coins
	//---------------------------------------Coin
	SDL_Texture *coinTexture{ IMG_LoadTexture(m_renderer,"../../res/img/gold.png") };
	SDL_Rect coinRect1{ rand() % (SCREEN_WIDTH - playerAnimPosition.w) + 10, rand() % (SCREEN_HEIGHT - SCREEN_HEIGHT / 5 - playerAnimPosition.h) + SCREEN_HEIGHT / 5 ,40,40 };
	SDL_Rect coinRect2{ rand() % (SCREEN_WIDTH - playerAnimPosition.w) + 10, rand() % (SCREEN_HEIGHT - SCREEN_HEIGHT / 5 - playerAnimPosition.h) + SCREEN_HEIGHT / 5 ,40,40 };

	//CounterPoints
	SDL_Texture *pointsTexture{ IMG_LoadTexture(m_renderer,"../../res/img/num.png") };
	SDL_Rect firtsNumPos, secondNumPos,numSpriteRect, numSpriteRect2;
	int textNumWidth, textNumHeight, frameNumWidth, frameNumHeight;
	SDL_QueryTexture(pointsTexture, NULL, NULL, &textNumWidth, &textNumHeight);

	frameNumWidth = textNumWidth / 10;
	frameNumHeight = textNumHeight / 1;

	firtsNumPos = { 0,0,50,50 };
	secondNumPos = { 50,0,50,50 };

	numSpriteRect ={ 0,0, frameNumWidth,frameNumHeight};
	numSpriteRect2 = { 0,0, frameNumWidth,frameNumHeight};
	int frameTimeAnimNum = 0;

	//Playr2
	SDL_Rect firtsNumPosP2, secondNumPosP2, numSpriteRectP2, numSpriteRect2P2;

	firtsNumPosP2 = { SCREEN_WIDTH-50,0,50,50 };
	secondNumPosP2 = { SCREEN_WIDTH-100,0,50,50 };

	numSpriteRectP2 = { 0,0, frameNumWidth,frameNumHeight };
	numSpriteRect2P2 = { 0,0, frameNumWidth,frameNumHeight };

	int frameTimeAnimNumP2 = 0;

	//function


	// ------------------------------------------------------------ GAME LOOP ---
	
	startTime= SDL_GetTicks();

	SDL_Event event;
	bool click = false;
	bool isRunning = true;
	bool isOnPlay = false;
	bool changedClick=false;

	int points1, points2;
	points1 = points2 = 0;

	bool aPressed, sPressed, dPressed, wPressed, upPressed, downPressed, leftPressed, rightPressed;
	aPressed= sPressed= dPressed= wPressed= upPressed= downPressed= leftPressed= rightPressed = false;

	while (isRunning) {
		frameStart = SDL_GetTicks();


		// HANDLE EVENTS
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:

				//exit
				if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;

				//Player1
				if (event.key.keysym.sym == SDLK_a)  aPressed = true ;
				else if (event.key.keysym.sym == SDLK_w)  wPressed = true ;
				else if (event.key.keysym.sym == SDLK_s) sPressed = true ;
				else if (event.key.keysym.sym == SDLK_d)  dPressed = true ;

				//Player2
				if (event.key.keysym.sym == SDLK_LEFT) leftPressed = true;
				else if (event.key.keysym.sym == SDLK_UP) upPressed = true;
				else if (event.key.keysym.sym == SDLK_DOWN) downPressed = true;
				else if (event.key.keysym.sym == SDLK_RIGHT) rightPressed = true;

				break;

			case SDL_KEYUP:
				//Player1
				if (event.key.keysym.sym == SDLK_a)  aPressed = false;
				else if (event.key.keysym.sym == SDLK_w)  wPressed = false;
				else if (event.key.keysym.sym == SDLK_s) sPressed = false;
				else if (event.key.keysym.sym == SDLK_d)  dPressed = false;

				//Player2
				if (event.key.keysym.sym == SDLK_LEFT) leftPressed = false;
				else if (event.key.keysym.sym == SDLK_UP) upPressed = false;
				else if (event.key.keysym.sym == SDLK_DOWN) downPressed = false;
				else if (event.key.keysym.sym == SDLK_RIGHT) rightPressed = false;

			case SDL_MOUSEMOTION:
				mousePos.x = event.motion.x;
				mousePos.y = event.motion.y;

			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
					click = true;
				else
					click = false;
				break;


			default:
				break;
			}
		}

		// ****************************************************************************************UPDATE

		
		SDL_QueryTexture(playerTexture, NULL, NULL, &w, &h);

		playerRect.x = event.motion.x - W / 2;
		playerRect.y = event.motion.y - H / 2;

		frameTimeAnim++;
		if (FPS / frameTimeAnim <= 9) {
			frameTimeAnim = 0;
			playerAnimRect.x += frameWidth;
			if (playerAnimRect.x >= textWidth)
				playerAnimRect.x = 0;
		}

		if (isOnPlay) {

			timeDisplayable = std::to_string(timeDown);

			//pLAYERmOV
			if (dPressed)
				playerAnimPosition.x += 5;
			if(sPressed)
				playerAnimPosition.y+=5;
			if (wPressed)
				playerAnimPosition.y -= 5;
			if (aPressed)
				playerAnimPosition.x -= 5;

			//player2
			if (rightPressed)
				playerAnimPosition2.x += 5;
			if (downPressed)
				playerAnimPosition2.y += 5;
			if (upPressed)
				playerAnimPosition2.y -= 5;
			if (leftPressed)
				playerAnimPosition2.x -= 5;


			//Time
			deltaTime = clock() - lastTime;
			lastTime = clock();
			deltaTime /= CLOCKS_PER_SEC;
			timeDown -= deltaTime;
			std::cout << timeDown << std::endl;

			

			if ((int)timeDown == 0) {
				isOnPlay=false;
				timeDown = 60;
			}

			//Playable ground
			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition, skyRect))
				playerAnimPosition.y = skyRect.h;
			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition, windowDown))
				playerAnimPosition.y = windowDown.y;
			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition, windowLeft))
				playerAnimPosition.x = windowLeft.w;
			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition, windowRight))
				playerAnimPosition.x = windowRight.x;

			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition2, skyRect))
				playerAnimPosition2.y = skyRect.h;
			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition2, windowDown))
				playerAnimPosition2.y = windowDown.y;
			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition2, windowLeft))
				playerAnimPosition2.x = windowLeft.w;
			if (PlayerCollisions::CheckCollisionSprites(playerAnimPosition2, windowRight))
				playerAnimPosition2.x = windowRight.x;

			//Coin
			if (PlayerCollisions::CheckCollisionCoin(playerAnimPosition, coinRect1)) {
				points1++;
				coinRect1.x = rand() % (SCREEN_WIDTH - playerAnimPosition.w) + 10;
				coinRect1.y = rand() % (SCREEN_HEIGHT - SCREEN_HEIGHT / 5 - playerAnimPosition.h) + SCREEN_HEIGHT / 5;
				IncPoints(frameTimeAnimNum, numSpriteRect, numSpriteRect2, frameNumWidth);

			}
			if (PlayerCollisions::CheckCollisionCoin(playerAnimPosition, coinRect2)) {
				points1++;
				coinRect2.x = rand() % (SCREEN_WIDTH - playerAnimPosition.w) + 10;
				coinRect2.y = rand() % (SCREEN_HEIGHT - SCREEN_HEIGHT / 5 - playerAnimPosition.h) + SCREEN_HEIGHT / 5;
				IncPoints(frameTimeAnimNum, numSpriteRect, numSpriteRect2, frameNumWidth);

			}
			if (PlayerCollisions::CheckCollisionCoin(playerAnimPosition2, coinRect1)) {
				points2++;
				coinRect1.x = rand() % (SCREEN_WIDTH - playerAnimPosition2.w) + 10;
				coinRect1.y = rand() % (SCREEN_HEIGHT - SCREEN_HEIGHT / 5 - playerAnimPosition.h) + SCREEN_HEIGHT / 5;
				IncPoints(frameTimeAnimNumP2, numSpriteRectP2, numSpriteRect2P2, frameNumWidth);

			}
			if (PlayerCollisions::CheckCollisionCoin(playerAnimPosition2, coinRect2)) {
				points2++;
				coinRect2.x = rand() % (SCREEN_WIDTH - playerAnimPosition2.w) + 10;
				coinRect2.y = rand() % (SCREEN_HEIGHT - SCREEN_HEIGHT / 5 - playerAnimPosition.h) + SCREEN_HEIGHT / 5;
				IncPoints(frameTimeAnimNumP2, numSpriteRectP2, numSpriteRect2P2, frameNumWidth);

			}
		}
		else if (!isOnPlay) {
			textureAuxTitle = PlayerCollisions::ChecKCollision(mousePos, textRectTitle) ? textureTitleHover : titleTexture;
			textureAuxPlay = PlayerCollisions::ChecKCollision(mousePos, textRectPlay) ? texturePlayHover : playTexture;
			textureAuxExit = PlayerCollisions::ChecKCollision(mousePos, textRectExit) ? textureExitHover : exitTexture;

			if (Mix_PlayingMusic()) {

				if (!Mix_PausedMusic()) {
					textureAuxSound = PlayerCollisions::ChecKCollision(mousePos, textRectSound) ? textureSoundOffHover : soundOffTexture;
					if (click&&PlayerCollisions::ChecKCollision(mousePos, textRectSound)) {
						Mix_PauseMusic();
						click = false;
					}
				}

				else {
					textureAuxSound = PlayerCollisions::ChecKCollision(mousePos, textRectSound) ? textureSoundOnHover : soundOnTexture;
					if (click&&PlayerCollisions::ChecKCollision(mousePos, textRectSound)) {
						Mix_ResumeMusic();
						click = false;
					}
				}

			}
			else
				textureAuxSound = soundOffTexture;

			if (PlayerCollisions::ChecKCollision(mousePos, textRectExit) && click) {
				isRunning = false;
			}

			if (PlayerCollisions::ChecKCollision(mousePos, textRectPlay) && click) {
				isOnPlay = true;
			}



		}

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}





		// ****************************************************************************************DRAW
		SDL_RenderClear(m_renderer);

		if (isOnPlay) {
			//Background
			SDL_RenderCopy(m_renderer, bgCastleTexture, nullptr, &bgCastleRect);

			//Player
			SDL_RenderCopy(m_renderer, playerAnimTexture, &playerAnimRect, &playerAnimPosition);
			//Player2
			SDL_RenderCopy(m_renderer, playerAnimTexture, &playerAnimRect, &playerAnimPosition2);

			//Coin
			SDL_RenderCopy(m_renderer, coinTexture, nullptr, &coinRect1);
			SDL_RenderCopy(m_renderer, coinTexture, nullptr, &coinRect2);

			//Points
			SDL_RenderCopy(m_renderer, pointsTexture, &numSpriteRect, &firtsNumPos);
			SDL_RenderCopy(m_renderer, pointsTexture, &numSpriteRect2, &secondNumPos);

			SDL_RenderCopy(m_renderer, pointsTexture, &numSpriteRectP2, &firtsNumPosP2);
			SDL_RenderCopy(m_renderer, pointsTexture, &numSpriteRect2P2, &secondNumPosP2);

			SDL_RenderCopy(m_renderer, texturePoints, nullptr, &pointsRect);//Title

		}
		else if (!isOnPlay) {
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
		}


		SDL_RenderPresent(m_renderer);

	}

		// --- DESTROY ---
		SDL_DestroyTexture(bgTexture);
		SDL_DestroyTexture(playerTexture);
		SDL_DestroyTexture(titleTexture);
		SDL_DestroyTexture(playTexture);
		SDL_DestroyTexture(soundOnTexture);
		SDL_DestroyTexture(soundOffTexture);
		SDL_DestroyTexture(exitTexture);
		SDL_DestroyTexture(bgCastleTexture);
		SDL_DestroyTexture(playerAnimTexture);
		SDL_DestroyTexture(coinTexture);




		Mix_Quit();
		IMG_Quit();
		TTF_Quit();
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);

		// --- QUIT ---
		SDL_Quit();

		return 0;
	}


