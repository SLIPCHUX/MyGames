#pragma once
#include "PlayerPawn.h"

class ActorBall
{
public:
	ActorBall();
	void CalculatePosition(const float deltaTime);
	void CalculateCollision(const PlayerPawn& p1, const PlayerPawn& pl2, const float arenaSizeX, const float arenaSizeY);
	float GetPosX() const;
	float GetPosY() const;
	float GetHalfSize() const;

	bool GetFirstStatus() const;
	bool GetSecondStatus() const;

	void SetFirstStatus(const bool flag);
	void SetSecondStatus(const bool flag);

	~ActorBall();

private:
	float posX;
	float posY;
	float dpX;
	float dpY;
	float halfSize;


	bool checkFirst;
	bool checkSecond;
};

