#pragma once

inline namespace Types {

	struct myRect {
		int x, y, w, h;
	};

	struct vec2 {
		int x, y;
	}; 

	struct Text {
		std::string text;
		SDL_Color color;
		std::string id;
	};

	struct Font	{
		std::string path;
		int size;
		std::string id;
	};

	enum GameState {Game,Ranking,Menu,SplashScreen};
	enum PowerStates {SpeedUp, ExtraLenght, MiniLenght};
}