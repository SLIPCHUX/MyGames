#pragma once
#include <map>
#include "Box.h"
#include "Sprite.h"
#include "GraphicsEngine.h"

class Track
{
public:
	Track();

	void Draw(GraphicsEngine textWindow);

	Box& GetLeftBorder();

	Box& GetRightBorder();

	bool isExisting() const;

	~Track();

private:
	void GenerateTextSprite();

private:
	enum selector
	{
		one,
		two,
		three,

	} spriteSelector;

	Box leftBorder;
	
	Box rightBorder;

	std::map<selector, Sprite> trackTextSprite;
};

