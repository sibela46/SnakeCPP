#include "Apple.h"

Apple::Apple()
{
	texture = TextureManager::LoadTexture("assets/stone.png");
	xPos = rand() % 640;
	yPos = rand() % 800;
}

Apple::~Apple()
{
}

void Apple::Update() {
	srcRect.w = 20;
	srcRect.h = 20;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = xPos;
	dstRect.y = yPos;
	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;
}

void Apple::Render() {
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}