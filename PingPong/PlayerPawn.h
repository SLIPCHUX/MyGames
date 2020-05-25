#pragma once
class PlayerPawn
{
public:
	PlayerPawn();
	void CalculateImpulse(const float delta_time);
	void CalculateCollision(const float arena_half_size_x, const float arena_half_size_y);

	float GetPlayerPos() const;
	float GetPlayerDp() const;
	float GetPlayerDdp() const;
	float GetPlayerHalfSizeX() const;
	float GetPlayerHalfSizeY() const;
	int GetScore() const;

	void SetPlayerPos(const float pos);
	void SetPlayerDp(const float dp);
	void SetPlayerDdp(const float ddp);
	void SetScore(const int score);

	PlayerPawn& operator++();

	~PlayerPawn();
private:
	float player_pos;
	float player_dp;
	float player_ddp;
	float player_half_size_x;
	float player_half_size_y;


	int score;
};

