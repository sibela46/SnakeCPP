#pragma once
#include <vector>
#include "GameObject.h"

using std::vector;

class GameObject;

class Snake
{
public:
	Snake(int x, int y);
	~Snake();

	void Render();
	void Update();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	GameObject* GetHead();
	void Grow();
	bool CheckSelfCollision();
	bool CheckOutCollision();
	int GetSpeed();

private:
	int bodyParts;
	int direction;
	int speed;

	GameObject* head;
	std::vector<GameObject*> body;
};