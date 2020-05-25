#pragma once
#include <iostream>
#include <string>

#include "Actor.h"
#include "GraphicsEngine.h"
#include "Track.h"
#include "PlayerPawn.h"
#include "Sprite.h"
#include "Coin.h"

class Enemy : public Actor
{
public:
	Enemy();
	
	void Move() override;

	void Draw(GraphicsEngine textWindow) override;

	void CheckColliding(Track track) override;

	void CheckColliding(PlayerPawn player) override;

	void CheckColliding(Enemy enemy) override;

	void CheckColliding(Coin coin) override;

	void SetPosition(int x, int y) override;

	void SetDirection(int dir);

	Box& GetBody() override;

	Type GetType() const override;

	bool IsExisting() const override;

	~Enemy();

private:
	enum Direction
	{
		NONE,
		LEFT,
		RIGHT
	} direction;

	bool isAlive;

	Box body;

	Sprite bodyTextSprite;
};

