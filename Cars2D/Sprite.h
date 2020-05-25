#pragma once
#include <windows.h>
#include <list>
#include <string>

class Sprite
{
public:
	Sprite();
	
	void AddLine(std::string line);

	void SetPosition(int x, int y);
	
	std::list<std::string>& GetSprite();

	COORD GetPosition();

	int GetWidth();

	int GetHeight();

	~Sprite();

private:
	std::list<std::string> sprite;
	
	COORD position;
};

