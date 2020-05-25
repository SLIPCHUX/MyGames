#pragma once

class GraphicsEngine;
class PlayerPawn;
class Enemy;
class Track;
class Box;
class Coin;

class Actor
{
public:
	Actor();

	virtual void Move() = 0;

	virtual void Draw(GraphicsEngine textWindow) = 0;
	
	virtual void CheckColliding(Track track) = 0;

	virtual void CheckColliding(PlayerPawn player) = 0;

	virtual void CheckColliding(Enemy enemy) = 0;

	virtual void CheckColliding(Coin coin) = 0;
	
	virtual void SetPosition(int x, int y) = 0;

	virtual Box& GetBody() = 0;

	virtual bool IsExisting() const = 0;

	~Actor();

public:
	enum Type
	{
		COIN,
		ENEMY,
		PLAYER,
		TRACK
	};

public:
	virtual Type GetType() const = 0;
};

