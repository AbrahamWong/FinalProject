#pragma once
#include "GameObject.h"
class PlayerFish : public GameObject
{
public:
	PlayerFish();
	PlayerFish(int x, int y, int width, int height);
	~PlayerFish();

	void Move(int xAmount, int yAmount, int maxX, int maxY);
	bool Intersect(PlayerFish *smol);

	void IncScore();
	void SetScore();
	int GetScore();
private:
	int health;
	int score;
};

