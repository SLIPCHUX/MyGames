#include "PlayerPawn.h"

PlayerPawn::PlayerPawn()
{
	speed = 2;
	health = 100;
	points = 0;

	bodyTextSprite.AddLine("0-^-0");
	bodyTextSprite.AddLine("|,_,|");
	bodyTextSprite.AddLine("|[_]|");
	bodyTextSprite.AddLine("0---0");

	bodyTextSprite.SetPosition(3, 20);

	body.SetLeft(bodyTextSprite.GetPosition().X);
	body.SetTop(bodyTextSprite.GetPosition().Y);
	body.SetHeight(bodyTextSprite.GetHeight());
	body.SetWidth(bodyTextSprite.GetWidth());
}

void PlayerPawn::Move()
{
	points++;
	int x = body.GetLeft();
	int y = body.GetTop();

	if (GetAsyncKeyState(VK_LEFT) && !leftLocked)
	{
		x -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) && !rightLocked)
	{
		x += speed;
	}
	if (GetAsyncKeyState(VK_UP) && !upLocked)
	{
		y -= speed / 2;
	}
	if (GetAsyncKeyState(VK_DOWN) && !downLocked)
	{
		y += speed;
	}

	body.SetLeft(x);
	body.SetTop(y);
	bodyTextSprite.SetPosition(x, y);
}

void PlayerPawn::Draw(GraphicsEngine textWindow)
{
	textWindow.Draw(bodyTextSprite);
}

void PlayerPawn::SetPosition(int x, int y)
{
}

Box & PlayerPawn::GetBody()
{
	return body;
}

Actor::Type PlayerPawn::GetType() const
{
	return PLAYER;
}

int PlayerPawn::GetHealth() const
{
	return this->health;
}

int PlayerPawn::GetPoints() const
{
	return points;
}

void PlayerPawn::CheckColliding(Track track)
{
	leftLocked = body.CheckColliding(track.GetLeftBorder());
	rightLocked = body.CheckColliding(track.GetRightBorder());
	upLocked = body.GetTop() <= track.GetLeftBorder().GetTop();
	downLocked = body.GetBottom() >= track.GetLeftBorder().GetBottom();
}

void PlayerPawn::CheckColliding(PlayerPawn player)
{
	// Do nothing
}

void PlayerPawn::CheckColliding(Enemy enemy)
{
	if (body.CheckColliding(enemy.GetBody()))
	{
		health -= 30;
	}
}

void PlayerPawn::CheckColliding(Coin coin)
{
	if (body.CheckColliding(coin.GetBody()))
	{
		points += 100;
		health += 10;
	}
}

bool PlayerPawn::IsExisting() const
{
	return (health > 0);
}

PlayerPawn::~PlayerPawn()
{
}
