#include "Coin.h"

Coin::Coin()
{
	colliding = false;

	bodyTextSprite.AddLine("($)");
	bodyTextSprite.SetPosition((rand() % 31) + 3, 0);

	body.SetLeft(bodyTextSprite.GetPosition().X);
	body.SetTop(0);
	body.SetHeight(bodyTextSprite.GetHeight());
	body.SetWidth(bodyTextSprite.GetWidth());
}

void Coin::Move()
{
	int x = body.GetLeft();
	int y = body.GetTop() + 1;

	body.SetTop(y);
	bodyTextSprite.SetPosition(x, y);
}

void Coin::Draw(GraphicsEngine textWindow)
{
	textWindow.Draw(bodyTextSprite);
}

void Coin::CheckColliding(Track track)
{
	if (body.CheckColliding(track.GetLeftBorder()) || body.CheckColliding(track.GetLeftBorder()))
	{
		colliding = true;
	}
	if (body.GetTop() >= track.GetLeftBorder().GetBottom())
	{
		colliding = true;
	}
}

void Coin::CheckColliding(PlayerPawn player)
{
	if (body.CheckColliding(player.GetBody()))
	{
		colliding = true;
	}
}

void Coin::CheckColliding(Enemy enemy)
{
	if (body.CheckColliding(enemy.GetBody()))
	{
		
	}
}

void Coin::CheckColliding(Coin coin)
{
	// Do nothing
}

void Coin::SetPosition(int x, int y)
{
	body.SetLeft(x);
	body.SetTop(y);
}

Box& Coin::GetBody()
{
	return this->body;
}

Actor::Type Coin::GetType() const
{
	return COIN;
}

int Coin::GetHealth() const
{
	return 0;
}

int Coin::GetPoints() const
{
	return 0;
}

bool Coin::IsExisting() const
{
	return !colliding;
}

Coin::~Coin()
{

}
