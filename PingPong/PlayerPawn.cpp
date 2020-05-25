#include "PlayerPawn.h"



PlayerPawn::PlayerPawn()
	: player_pos(0.f), player_dp(0.f), player_ddp(0.f), player_half_size_x(2.f), player_half_size_y(12.f), score(0)
{

}


void PlayerPawn::CalculateImpulse(const float delta_time)
{
	player_ddp -= player_dp * 10.f;
	player_pos = player_pos + player_dp * delta_time + player_ddp * delta_time * delta_time * 0.5f;
	player_dp = player_dp + player_ddp * delta_time;
}

void PlayerPawn::CalculateCollision(const float arena_half_size_x, const float arena_half_size_y)
{
	if (player_pos + player_half_size_y > arena_half_size_y)
	{
		player_pos = arena_half_size_y - player_half_size_y;
		player_dp *= -1;
	}
	else if (player_pos - player_half_size_y < -arena_half_size_y)
	{
		player_pos = -arena_half_size_y + player_half_size_y;
		player_dp *= -1;
	}
}

float PlayerPawn::GetPlayerPos() const
{
	return this->player_pos;
}

float PlayerPawn::GetPlayerDp() const
{
	return this->player_dp;
}

float PlayerPawn::GetPlayerDdp() const
{
	return this->player_ddp;
}

float PlayerPawn::GetPlayerHalfSizeX() const
{
	return this->player_half_size_x;
}

float PlayerPawn::GetPlayerHalfSizeY() const
{
	return this->player_half_size_y;
}

int PlayerPawn::GetScore() const
{
	return this->score;
}

void PlayerPawn::SetPlayerPos(const float pos)
{
	this->player_pos = pos;
}

void PlayerPawn::SetPlayerDp(const float dp)
{
	this->player_dp = dp;
}

void PlayerPawn::SetPlayerDdp(const float ddp)
{
	this->player_ddp = ddp;
}

void PlayerPawn::SetScore(const int score)
{
	this->score = score;
}

PlayerPawn& PlayerPawn::operator++()
{
	this->score++;
	return *this;
}

PlayerPawn::~PlayerPawn()
{
}
