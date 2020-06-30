#pragma once
#include "TextureManager.h"
#include <tuple>

using std::tuple;

class GameObject
{
public:
	GameObject(const char* textureFile, int x, int y, int squareSize);
	~GameObject();

	void Update();
	void Render();

	tuple<int, int> GetPosition();

	int xPos, yPos, size;

private:
	SDL_Texture *texture;
	SDL_Rect srcRect, dstRect;
};