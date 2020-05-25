#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memDC, memDCBack;
	PAINTSTRUCT ps;

	static HBITMAP hBmp, hBmpBack;
	static int yPos = 0;
	static RECT rect;

	switch (iMsg)
	{
	default:
		break;
	}
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = WndProc;

	RegisterClass(&window_class);

	HWND hWnd = CreateWindow(window_class.lpszClassName, L"The Snake Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 800, 0, 0, hInstance, 0);

}

