#include "PlayerFish.h"



PlayerFish::PlayerFish()
{
	this->health = 10;
	this->score = 0;
}


PlayerFish::~PlayerFish()
{
}

void PlayerFish::Move(int xAmount, int yAmount, int maxX, int maxY)
{
	/*wxMessageOutputDebug().Printf("y: %d.", y);
	wxMessageOutputDebug().Printf("x: %d.", maxY);
	wxMessageOutputDebug().Printf("ym-h: %d.", maxY - height);*/
	
	if (this->GetPosX() + this->GetWidth() >= maxX)
	{
		this->SetPosX(maxX - 1);
	}
	else if (this->GetPosX() <= 0)
	{
		this->SetPosX(1);
	}
	else if (this->GetPosX() >= maxX - this->GetWidth() - xAmount)
	{
		//wxMessageOutputDebug().Printf("masuk sini");
		this->SetPosX(this->GetPosX() - xAmount);
	}
	else
		this->SetPosX(this->GetPosX() + xAmount);

	if (this->GetPosY() + this->GetHeight() >= maxY)
	{
		this->SetPosY(maxY - 1);
	}
	else if (this->GetPosY() <= 0)
	{
		this->SetPosY(1);
	}
	else if (this->GetPosY() >= maxY - this->GetHeight() - yAmount) {
		wxMessageOutputDebug().Printf("masuk y sini");
		this->SetPosY(this->GetPosY() - yAmount);
	}
	this->SetPosY(this->GetPosY() + yAmount);

	if (this->GetPosX() > 1280 || this->GetPosX() < 0 ||
		this->GetPosY() > 720 || this->GetPosY() < 0)
	{
		wxMessageBox(wxT("Game Over"));
	}
}

bool PlayerFish::Intersect(PlayerFish *smol)
{
	return ((abs(this->GetPosX() - smol->GetPosX()) * 2 < (this->GetWidth() + smol->GetWidth())) &&
		(abs(this->GetPosY() - smol->GetPosY()) * 2 < (this->GetHeight() + smol->GetHeight())));
}

void PlayerFish::IncScore() {
	this->score += 1;
}

int PlayerFish::GetScore() {
	return this->score;
}

void PlayerFish::SetScore() {
	this->score = 0;
}