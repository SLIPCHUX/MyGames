#include "Game.h"
#include <ctime>


Game::Game()
	: isPlayerAlive(true), callsToCreate(17), points(0)
{
	PlayerPawn* p = new PlayerPawn();
	this->player = p;
	actors.push_back(p);
}

void Game::Run()
{
	srand(time(NULL));
	GraphicsEngine textWindow(50, 50);

	while (isPlayerAlive)
	{
		GenerateObjects();
		CheckCollision();
		MoveObjects();
		GetDataFromPlayer();
		RemoveObjects();
		DrawObjects(textWindow);
		DrawValues(textWindow);

		textWindow.Display();
		Delay();
		textWindow.Clear();
	}
}

void Game::GenerateObjects()
{
	static int i = 0;
	i++;
	if (i == callsToCreate)
	{
		i = 0;
		Enemy* enemy = new Enemy();
		actors.push_back(enemy);

		if (points < 500)
		{
			callsToCreate = 17;
		}
		else if (points < 1000)
		{
			callsToCreate = 15;
		}
		else if(points < 1500)
		{
			callsToCreate = 13;
		}
		else if (points < 2000)
		{
			callsToCreate = 11;
		}
		else
		{
			callsToCreate = 9;
		}
	}
	if (i % 20 == 0)
	{
		Coin* c = new Coin();	// TODO: Create class of Coin 
		actors.push_back(c);
	}
}

void Game::MoveObjects()
{
	for (std::list<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it)
	{
		(*it)->Move();
	}
}

void Game::RemoveObjects()
{
	for (std::list<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it)
	{
		if ((*it)->IsExisting() == false)
		{
			delete (*it);
			actors.remove(*it);
			break;
		}
	}
}

void Game::CheckCollision()
{
	int i = 0, j = 0;
	for (std::list<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it)
	{
		i++;
		(*it)->CheckColliding(track);
		for (std::list<Actor*>::iterator collider = actors.begin(); collider != actors.end(); ++collider)
		{
			j++;
			if (i != j)
			{
				switch ((*collider)->GetType())
				{
				case Actor::ENEMY:
					(*it)->CheckColliding(*(reinterpret_cast<Enemy*>(*collider)));
					break;
				
				case Actor::PLAYER:
					(*it)->CheckColliding(*(reinterpret_cast<PlayerPawn*>(*collider)));
					break;

				case Actor::COIN:
					(*it)->CheckColliding(*(reinterpret_cast<Coin*>(*collider)));
					break;
				}
			}
		}
		j = 0;
	}
}

void Game::GetDataFromPlayer()
{
	isPlayerAlive = player->IsExisting();
	points = player->GetPoints();
}

bool Game::GetIsPlayerAlive()
{
	return this->isPlayerAlive;
}

void Game::Delay()
{
	if (isPlayerAlive)
	{
		Sleep(20);
	}
	else
	{
		Sleep(3000);
	}
}

void Game::DrawObjects(GraphicsEngine textWindow)
{
	track.Draw(textWindow);

	for (std::list<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it)
	{
		(*it)->Draw(textWindow);
	}
}

void Game::DrawValues(GraphicsEngine textWindow)
{
	Sprite valuesTextSprite;
	valuesTextSprite.SetPosition(50, 10);

	std::string pointBar = "POINTS: " + std::to_string(player->GetPoints());
	std::string healthBar = "HEALTH: " + std::to_string(player->GetHealth());

	valuesTextSprite.AddLine(pointBar);
	valuesTextSprite.AddLine(healthBar);

	textWindow.Draw(valuesTextSprite);
}

Game::~Game()
{
}