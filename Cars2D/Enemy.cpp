#include "Enemy.h"

Enemy::Enemy()
{
	const int per_pos = 37;

	isAlive = true;

	bodyTextSprite.AddLine(" ____ ");
	bodyTextSprite.AddLine("0 __ 0");
	bodyTextSprite.AddLine("|[__]|");
	bodyTextSprite.AddLine("|\\__/|");
	bodyTextSprite.AddLine("0,~~,0");

	bodyTextSprite.SetPosition(rand() % per_pos, 0);

	body.SetLeft(bodyTextSprite.GetPosition().X);
	body.SetTop(bodyTextSprite.GetPosition().Y);
	body.SetHeight(bodyTextSprite.GetHeight());
	body.SetWidth(bodyTextSprite.GetWidth());
}

void Enemy::Move()
{
	int x = body.GetLeft();
	int y = body.GetTop();

	switch (direction)
	{
	case LEFT:
		x--;
		y++;
		break;

	case RIGHT:
		x++;
		y++;
		break;

	default:
		y += 2;
		break;
	}

	body.SetLeft(x);
	body.SetTop(y);
	bodyTextSprite.SetPosition(x, y);
}

void Enemy::Draw(GraphicsEngine textWindow)
{
	textWindow.Draw(bodyTextSprite);
}

void Enemy::CheckColliding(Track track)
{
	if (body.CheckColliding(track.GetLeftBorder()))
	{
		direction = RIGHT;
	}
	if (body.CheckColliding(track.GetRightBorder()))
	{
		direction = LEFT;
	}
	if (body.GetTop() >= track.GetLeftBorder().GetBottom())
	{
		isAlive = false;
	}
}

void Enemy::CheckColliding(PlayerPawn player)
{
	if (body.CheckColliding(player.GetBody()))
	{
		isAlive = false;
	}
}

void Enemy::CheckColliding(Enemy enemy)
{
	if (body.CheckColliding(enemy.GetBody()))
	{
		switch (direction)
		{
		case LEFT:
			direction = RIGHT;
			break;

		case RIGHT:
			direction = LEFT;
			break;

		default:
			break;
		}
	}
}

void Enemy::CheckColliding(Coin coin)
{
	// Do Nothing
}

void Enemy::SetPosition(int x, int y)
{
	body.SetLeft(x);
	body.SetTop(y);
}

void Enemy::SetDirection(int dir = 0)
{
	const int per_dir = 8;

	int variable = rand() % per_dir;

	//direction = static_cast<Direction>(dir);

	switch (variable)
	{
	case 2:
		direction = LEFT;
		break;

	case 4:
		direction = RIGHT;
		break;

	default:
		direction = NONE;
		break;
	}
}

Box& Enemy::GetBody()
{
	return this->body;
}

Actor::Type Enemy::GetType() const
{
	return ENEMY;
}

bool Enemy::IsExisting() const
{
	return isAlive;
}

Enemy::~Enemy()
{

}
