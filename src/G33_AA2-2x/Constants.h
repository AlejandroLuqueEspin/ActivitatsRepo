#pragma once
#include "Types.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60

//*******************************************************
const Rect gameScreen{ 25, 27, SCREEN_WIDTH - 45, 437 };

const Rect locationP1Respawn{ SCREEN_WIDTH / 2 - 350, 250, 60, 20 };
const Rect locationP2Respawn{ SCREEN_WIDTH / 2 + 290, 250, 60, 20 };

const Rect locationScoreP1{ 100, 500, 200, 50 };
const Rect locationScoreP2{ 500, 500, 200, 50 };

const Rect locationLife1P1{ 95, 550, 60, 20 };
const Rect locationLife2P1{ 175, 550, 60, 20 };
const Rect locationLife3P1{ 255, 550, 60, 20 };

const Rect locationLife1P2{ 480, 550, 60, 20 };
const Rect locationLife2P2{ 560, 550, 60, 20 };
const Rect locationLife3P2{ 640, 550, 60, 20 };
//*********************************************************
const Vec2 ballRespawnP1{ (SCREEN_WIDTH / 2) - 300, SCREEN_HEIGHT/2 };
const Vec2 ballRespawnP2{ (SCREEN_WIDTH / 2) + 300, SCREEN_HEIGHT / 2};
const Vec2 buttonSize{ 175, 75 };
//**********************************************************
const Color blue{ 0, 0, 255, 255 };
const Color red{ 255, 0, 0, 255 };
const Color yellow{ 255, 255, 0, 255 };
const Color green{ 46, 149, 16, 255 };
const Color white{ 255, 255, 255, 255 };