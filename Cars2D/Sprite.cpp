#include "Sprite.h"

Sprite::Sprite()
{
}

void Sprite::AddLine(std::string line)
{
	this->sprite.push_back(line);
}

void Sprite::SetPosition(int x, int y)
{
	this->position.X = x;
	this->position.Y = y;
}

std::list<std::string>& Sprite::GetSprite()
{
	return this->sprite;
}

COORD Sprite::GetPosition()
{
	return this->position;
}

int Sprite::GetWidth()
{
	return this->sprite.back().size();
}

int Sprite::GetHeight()
{
	return this->sprite.size();
}


Sprite::~Sprite()
{
}
