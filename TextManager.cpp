#include "TextManager.h"

TTF_Font* TextManager::font = nullptr;

TextManager::TextManager(const std::string &font_path, int font_size) {
	LoadFont(font_path, font_size);
}

TextManager::~TextManager() {

}

void TextManager::Display(int x, int y, const std::string &message_text, const SDL_Colour &colour) {
	text_texture = CreateMessageSurface(message_text, colour);
	SDL_QueryTexture(text_texture, nullptr, nullptr, &text_rect.w, &text_rect.h); //Gives width and height to texture based on font size
	text_rect.x = (x - text_rect.w) / 2;
	text_rect.y = y;

	SDL_RenderCopy(Game::renderer, text_texture, nullptr, &text_rect);
}

void TextManager::LoadFont(const std::string &font_path, int font_size) {
	font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font) {
		std::cerr << "Failed to load font\n";
	}
}

SDL_Texture* TextManager::CreateMessageSurface(const std::string &message_text, const SDL_Colour &colour) {
	auto text_surface = TTF_RenderText_Solid(TextManager::font, message_text.c_str(), colour);
	if (!text_surface) {
		std::cerr << "Failed to create text surface\n";
	}
	auto text_texture = SDL_CreateTextureFromSurface(Game::renderer, text_surface);
	if (!text_texture) {
		std::cerr << "Failed to create text texture\n";
	}
	SDL_FreeSurface(text_surface);

	return text_texture;
}