#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Grid.h"
#include "Snake.h"
#include "TextManager.h"

#undef main

using namespace std;

class Snake;
class GameObject;
class TextManager;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, bool fullScreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer *renderer;
	const static int windowWidth = 800;
	const static int windowHeight = 640;

private:
	bool isRunning;
	bool isGameOver;
	int score = 0;

	Grid *grid;
	Snake *snake;
	TextManager *scoreText;
	GameObject *apple;
	string scoreMessageText;

	SDL_Window *window;

	int GetRandomWithStep(int maxValue, int minValue, int step);
	bool CheckForCollision();
};