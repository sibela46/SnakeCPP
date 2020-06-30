#include "Grid.h"
#include "TextureManager.h"

Grid::Grid() {
	tile = TextureManager::LoadTexture("assets/tile.png");
	stone = TextureManager::LoadTexture("assets/stone.png");

	srcRect.x = srcRect.y = 0;
	srcRect.w = dstRect.w = 20;
	srcRect.h = dstRect.h = 20;
	dstRect.x = dstRect.y = 0;
}

void Grid::DrawGrid() {
	int type = 0;

	for (int row = 0; row < Game::windowHeight/srcRect.h; row++) {
		for (int col = 0; col < Game::windowWidth/srcRect.w; col++) {
			dstRect.x = col * srcRect.h;
			dstRect.y = row * srcRect.w;
			TextureManager::Draw(tile, srcRect, dstRect);
		}
	}
}