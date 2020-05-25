#pragma once
#include <windows.h>

#include "Sprite.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	
	GraphicsEngine(unsigned int width, unsigned int height);

	void Draw(Sprite sprite);

	void Display();

	void Clear();
	
	~GraphicsEngine();

private:
	bool switcher;
	
	HANDLE windowBufferOne;

	HANDLE windowBufferTwo;

	HANDLE* activeWindowBuffer;

	HANDLE* backgroundWindowBuffer;
};

