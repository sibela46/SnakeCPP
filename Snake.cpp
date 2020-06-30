#include "Snake.h"

Snake::Snake(int x, int y)
{
	head = new GameObject("assets/snake.png", x, y, 20);

	bodyParts = 3;
	for (int i = 0; i < bodyParts; ++i) {
		body.push_back(new GameObject("assets/snake.png", 100 - (i + 1) * head->size, 480, 20));
	}

	direction = 2; // UP -1 DOWN 1 LEFT -2 RIGHT 2
	speed = 1;
}

Snake::~Snake()
{
}

void Snake::MoveRight() {
	if (direction != -2) {
		direction = 2;
	}
}

void Snake::MoveLeft() {
	if (direction != 2) {
		direction = -2;
	}
}

void Snake::MoveUp() {
	if (direction != 1) {
		direction = -1;
	}
}

void Snake::MoveDown() {
	if (direction != -1) {
		direction = 1;
	}
}

void Snake::Update() {
	head->Update();
	for (vector<GameObject*>::iterator it = body.begin(); it != body.end(); ++it) {
		(*it)->Update();
	}
	int x = head->xPos;
	int y = head->yPos;
	int prevX = head->xPos;
	int prevY = head->yPos;
	switch (direction) {
	case 1: //DOWN
		y = (y + head->size);
		break;
	case -1: //UP
		y = (y - head->size);
		break;
	case 2: //RIGHT
		x = (x + head->size);
		break;
	case -2: //LEFT
		x = (x - head->size);
		break;
	default:
		break;
	}

	head->xPos = x;
	head->yPos = y;
	int oldX = body.front()->xPos;
	int oldY = body.front()->yPos;
	int offsetY = (abs(direction) == 1) ? direction : 0;
	body.front()->xPos = prevX;// +(direction / 2) * head->size * (speed + 1);
	body.front()->yPos = prevY;// +offsetY * head->size * (speed + 1);
	prevX = oldX;
	prevY = oldY;
	for (vector<GameObject*>::iterator it = body.begin() + 1; it != body.end(); ++it) {
		int oldX = (*it)->xPos;
		int oldY = (*it)->yPos;
		(*it)->xPos = prevX;// +(direction / 2) * head->size * (speed + 1);
		(*it)->yPos = prevY;// +offsetY * head->size * (speed + 1);
		prevX = oldX;
		prevY = oldY;
	}

}


void Snake::Render() {
	head->Render();
	for (vector<GameObject*>::iterator it = body.begin(); it != body.end(); ++it) {
		(*it)->Render();
	}
}

GameObject* Snake::GetHead() {
	return head;
}

void Snake::Grow() {
	bodyParts++;
	body.push_back(new GameObject("assets/snake.png", body.back()->xPos, body.back()->yPos, 20));
}

bool Snake::CheckSelfCollision() {
	for (vector<GameObject*>::iterator it = body.begin()+1; it != body.end(); ++it) {
		if ((*it)->xPos == head->xPos && (*it)->yPos == head->yPos) {
			return true;
		}
	}
	return false;
}

bool Snake::CheckOutCollision() {
	if (head->xPos > Game::windowWidth || head->xPos < 0 || head->yPos > Game::windowHeight || head->yPos < 0) {
		return true;
	}
	return false;
}

int Snake::GetSpeed() {
	return speed;
}