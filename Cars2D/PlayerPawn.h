#pragma once
#include <iostream>
#include <string>

#include "Actor.h"
#include "Box.h"
#include "GraphicsEngine.h"
#include "Sprite.h"
#include "Track.h"
#include "Enemy.h"


class PlayerPawn : public Actor
{
public:
	PlayerPawn();

	void Move() override;

	void Draw(GraphicsEngine textWindow) override;

	void DrawValues(GraphicsEngine textWindow);

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

	~PlayerPawn();

private:
	int speed;
	int health;
	int points;

	bool leftLocked;
	bool rightLocked;
	bool upLocked;
	bool downLocked;

	Box body;
	Sprite bodyTextSprite;
};

