#include "GameObject.h"

GameObject::GameObject(const char* textureFile, int x, int y, int squareSize)
{
	texture = TextureManager::LoadTexture(textureFile);
	xPos = x;
	yPos = y;
	size = squareSize;
}


GameObject::~GameObject()
{
}

void GameObject::Update() {
	srcRect.w = size;
	srcRect.h = size;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = xPos;
	dstRect.y = yPos;
	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}

std::tuple<int, int> GameObject::GetPosition() {
	return std::make_tuple(xPos, yPos);
}