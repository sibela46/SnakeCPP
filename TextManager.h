#pragma once
#include "SDL_ttf.h"
#include <string>
#include "Game.h"

class TextManager
{
public:
	TextManager(const std::string &font_path, int font_size);
	~TextManager();

	static TTF_Font *font;
	void Display(int x, int y, const std::string &message_text, const SDL_Colour &colour);
	static void LoadFont(const std::string &font_path, int font_size);
	static SDL_Texture* CreateMessageSurface(const std::string &message_text, const SDL_Colour &colour);

private:
	SDL_Texture *text_texture;
	SDL_Rect text_rect;
	static int surfaceWidth, surfaceHeight;
};

