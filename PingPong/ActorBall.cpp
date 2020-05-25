#include "ActorBall.h"



ActorBall::ActorBall()
	: posX(0.f), posY(0.f), dpX(100.f), dpY(0.f), halfSize(2.f), checkFirst(false), checkSecond(false)
{
}


void ActorBall::CalculatePosition(const float deltaTime)
{
	this->posX += this->dpX * deltaTime;
	this->posY += this->dpY * deltaTime;

}

void ActorBall::CalculateCollision(const PlayerPawn& p1, const PlayerPawn& p2, const float arenaSizeX, const float arenaSizeY)
{
	//Collision with Players
	if (this->posX + this->halfSize > 80 - p1.GetPlayerHalfSizeX() &&
		this->posX - this->halfSize < 80 + p1.GetPlayerHalfSizeX() &&
		this->posY + this->halfSize > p1.GetPlayerPos() - p1.GetPlayerHalfSizeY() &&
		this->posY + this->halfSize < p1.GetPlayerPos() + p1.GetPlayerHalfSizeY())
	{
		this->posX = 80 - p1.GetPlayerHalfSizeX() - this->halfSize;
		this->dpX *= -1;
		this->dpY = (this->posY - p1.GetPlayerPos()) * 2 + p1.GetPlayerDp() * 0.75f;
	}
	else if (this->posX + this->halfSize > -80 - p2.GetPlayerHalfSizeX() &&
		this->posX - this->halfSize < -80 + p2.GetPlayerHalfSizeX() &&
		this->posY + this->halfSize > p2.GetPlayerPos() - p2.GetPlayerHalfSizeY() &&
		this->posY + this->halfSize < p2.GetPlayerPos() + p2.GetPlayerHalfSizeY())
	{
		this->posX = -80 + p2.GetPlayerHalfSizeX() + this->halfSize;
		this->dpX *= -1;
		this->dpY = (this->posY - p2.GetPlayerPos()) * 2 + p2.GetPlayerDp() * 0.75f;
	}

	//Collision with Arena
	if (this->posY + this->halfSize > arenaSizeY)
	{
		this->posY = arenaSizeY - this->halfSize;
		this->dpY *= -1;
	}
	else if (this->posY - this->halfSize < -arenaSizeY)
	{
		this->posY = -arenaSizeY + this->halfSize;
		this->dpY *= -1;
	}

	if (this->posX + this->halfSize > arenaSizeX)
	{
		this->dpX *= -1;
		this->dpY = 0;
		this->posX = 0;
		this->posY = 0;
		checkFirst = true;
	}
	else if (this->posX - this->halfSize < -arenaSizeX)
	{
		this->dpX *= -1;
		this->dpY = 0;
		this->posX = 0;
		this->posY = 0;
		checkSecond = true;
	}
}

float ActorBall::GetPosX() const
{
	return this->posX;
}

float ActorBall::GetPosY() const
{
	return this->posY;
}

float ActorBall::GetHalfSize() const
{
	return this->halfSize;
}

bool ActorBall::GetFirstStatus() const
{
	return this->checkFirst;
}

bool ActorBall::GetSecondStatus() const
{
	return this->checkSecond;
}

void ActorBall::SetFirstStatus(const bool flag)
{
	this->checkFirst = flag;
}

void ActorBall::SetSecondStatus(const bool flag)
{
	this->checkSecond = flag;
}

ActorBall::~ActorBall()
{
}
