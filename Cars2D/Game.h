#pragma once
#include <list>

#include "Track.h";
#include "Actor.h"
#include "Enemy.h"
#include "PlayerPawn.h"
#include "GraphicsEngine.h"
#include "Coin.h"

class Game
{
public:
	Game();

	void Run();

	void GenerateObjects();
	
	void MoveObjects();

	void RemoveObjects();

	void DrawObjects(GraphicsEngine textWindow);	// TODO parameters

	void DrawValues(GraphicsEngine textWindow);

	void DrawGameOver(); // TODO params
	
	void CheckCollision();

	void GetDataFromPlayer();

	bool GetIsPlayerAlive();

	void Delay();

	~Game();

private:
	std::list<Actor*> actors;
	
	Track track;
	
	PlayerPawn* player;
	
	int callsToCreate;
	
	bool isPlayerAlive;
	
	int points;
};

