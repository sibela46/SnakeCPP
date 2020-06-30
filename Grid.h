#pragma once
#include "SDL.h"

class Grid {
public:
	Grid();
	~Grid();

	void DrawGrid();

private:
	SDL_Rect srcRect, dstRect;

	SDL_Texture* tile;
	SDL_Texture* stone;
};