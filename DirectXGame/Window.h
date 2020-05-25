#pragma once


class Window
{
public:
	Window();

	// Initialize the window
	bool InitWindow();

	// Release the window
	bool ReleaseWindow();

	~Window();
};