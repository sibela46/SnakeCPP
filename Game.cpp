#include "Game.h"
#include "TextureManager.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, bool fullScreen)
{
	int flags = 0;
	if (fullScreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, windowWidth, windowHeight, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	if (TTF_Init() == -1) {
		std::cerr << "Could not initialise TTF library";
	}


	grid = new Grid();
	scoreText = new TextManager("assets/myriad_pro.ttf", 30);
	snake = new Snake(100, 480);
	apple = new GameObject("assets/apple.png", GetRandomWithStep(windowWidth, 0, snake->GetHead()->size), GetRandomWithStep(windowHeight, 0, snake->GetHead()->size), 5);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		std::cout << event.key.keysym.sym;
		case SDLK_LEFT:
			snake->MoveLeft();
			break;
		case SDLK_RIGHT:
			snake->MoveRight();
			break;
		case SDLK_UP:
			if (isGameOver) {
				isGameOver = false;
				delete snake;
				delete apple;
				snake = new Snake(100, 480);
				apple = new GameObject("assets/apple.png", GetRandomWithStep(windowWidth, 0, snake->GetHead()->size), GetRandomWithStep(windowHeight, 0, snake->GetHead()->size), 5);
			}
			else {
				snake->MoveUp();
			}
			break;
		case SDLK_DOWN:
			snake->MoveDown();
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Game::update()
{
	if (isGameOver) {
		scoreText->Display(windowWidth / 2, windowHeight / 2, "Game Over! Press Enter to start again", { 255, 255, 255 });
		return;
	}

	snake->Update();
	apple->Update();
	
	std::tuple<int, int> snakePos = snake->GetHead()->GetPosition();
	std::tuple<int, int> applePos = apple->GetPosition();
	if ((std::get<0>(snakePos) == std::get<0>(applePos)) && (std::get<1>(snakePos) == std::get<1>(applePos))) {
		delete apple;
		apple = new GameObject("assets/apple.png", GetRandomWithStep(windowWidth, 0, snake->GetHead()->size), GetRandomWithStep(windowHeight, 0, snake->GetHead()->size), 5);
		snake->Grow();
		score++;

	}
	if (snake->CheckSelfCollision() || snake->CheckOutCollision()) {
		isGameOver = true;
		scoreMessageText = "Game Over! Press Up arrow key to start again.";
	}
	else {
		scoreMessageText = "Score " + std::to_string(score);
	}

}

void Game::render()
{
	SDL_RenderClear(renderer);
	grid->DrawGrid();
	scoreText->Display(windowWidth, 50, scoreMessageText, { 255, 255, 255 });
	snake->Render();
	apple->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

int Game::GetRandomWithStep(int maxValue, int minValue, int step)
{
	int random_value = (rand() % ((++maxValue - minValue) / step)) * step + minValue;
	return random_value;
}
