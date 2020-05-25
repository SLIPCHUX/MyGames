#pragma once

#include "Actor.h"
#include "PlayerPawn.h"
#include "Enemy.h"
#include "GraphicsEngine.h"
#include "Sprite.h"
#include "Box.h"

class Coin : public Actor
{
public:
	Coin();

	void Move() override;

	void Draw(GraphicsEngine textWindow) override;

	void CheckColliding(Track track) override;

	void CheckColliding(PlayerPawn player) override;

	void CheckColliding(Enemy enemy) override;

	void CheckColliding(Coin coin) override;

	void SetPosition(int x, int y) override;

	Box& GetBody() override;

	Type GetType() const override;

	int GetHealth() const;

	int GetPoints() const;

	bool IsExisting() const;

	~Coin();

private:
	bool colliding;

	Box body;

	Sprite bodyTextSprite;
};

