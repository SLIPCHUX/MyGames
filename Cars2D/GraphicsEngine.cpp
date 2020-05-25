#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{
	switcher = false;
	windowBufferOne = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	windowBufferTwo = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	activeWindowBuffer = &windowBufferOne;
	backgroundWindowBuffer = &windowBufferTwo;
}

GraphicsEngine::GraphicsEngine(unsigned int width, unsigned int height)
	: GraphicsEngine() // Delegating Constructor
{
	SMALL_RECT rect = { 0, 0, width, height };

	SetConsoleWindowInfo(windowBufferOne, 1, &rect);
	SetConsoleWindowInfo(windowBufferTwo, 1, &rect);
}

void GraphicsEngine::Draw(Sprite sprite)
{
	COORD cord = sprite.GetPosition();
	DWORD written;

	for (std::list<std::string>::iterator line = sprite.GetSprite().begin(); line != sprite.GetSprite().end(); ++line)
	{
		for (std::string::iterator ch = (*line).begin(); ch != (*line).end(); ++ch)
		{
			SetConsoleCursorPosition(*backgroundWindowBuffer, cord);
			FillConsoleOutputCharacterA(*backgroundWindowBuffer, *ch, 1, cord, &written);
			cord.X++;
		}
		cord.X = sprite.GetPosition().X;
		cord.Y++;
	}
}

void GraphicsEngine::Display()
{
	CONSOLE_SCREEN_BUFFER_INFO windowInfo;
	GetConsoleScreenBufferInfo(&activeWindowBuffer, &windowInfo);
	SetConsoleScreenBufferSize(&backgroundWindowBuffer, windowInfo.dwSize);

	switcher = !switcher;
	activeWindowBuffer = (switcher == false) ? &windowBufferOne : &windowBufferTwo;
	backgroundWindowBuffer = (switcher == false) ? &windowBufferTwo : &windowBufferOne;

	SetConsoleActiveScreenBuffer(*activeWindowBuffer);
}

void GraphicsEngine::Clear()
{ 
	COORD topLeft = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO bufferWindowInfo;
	DWORD written;

	GetConsoleScreenBufferInfo(*backgroundWindowBuffer, &bufferWindowInfo);
	FillConsoleOutputCharacterA(*backgroundWindowBuffer, ' ', bufferWindowInfo.dwSize.X * bufferWindowInfo.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(*backgroundWindowBuffer, topLeft);
}


GraphicsEngine::~GraphicsEngine()
{
}
