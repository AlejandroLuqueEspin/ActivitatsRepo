#pragma once
#include <string>
#include "Vec2.h"
struct Font
{
	std::string path, id;
	int size;
};

struct Color {
	unsigned char r, g, b, a;
};


struct Text
{
	std::string text, id;
	Color color;
};

struct Rect
{
	int x, y, w, h;
};
enum ScreenLocation {UP,DOWN,RIGHT,LEFT};
enum PlayerNum {P1, P2};
enum PowerUpType {EXTRA,MINI,SPEED};
enum PowerUpPlayerState {ACTIVE,NOACTIVE,NULLE};