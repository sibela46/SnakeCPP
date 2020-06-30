#pragma once
#include "TextureManager.h"

class Apple
{
public:
	Apple();
	~Apple();

	void Update();
	void Render();

	int xPos, yPos;

private:
	SDL_Texture *texture;
	SDL_Rect srcRect, dstRect;
};
