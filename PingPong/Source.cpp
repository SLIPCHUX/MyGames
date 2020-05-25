#include "Utils.cpp"
#include <stdlib.h>
#include <windows.h>
#include "PlayerPawn.h"
#include "ActorBall.h" 
#include <stdio.h>

global_variable bool running = true;

struct Render_State
{
	int height, width;
	void* memory;

	BITMAPINFO bitmapinfo;

};
global_variable Render_State render_state;

PlayerPawn firstPlayer;
PlayerPawn secondPlayer;
ActorBall ball;

#include "Render.cpp"
#include "PlatformCommon.cpp"
#include "Game.cpp"

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (uMsg)
	{
		case WM_CLOSE:
		case WM_DESTROY:
		{
			running = false;
		} break;
		case WM_SIZE:
		{
			RECT rect;
			GetClientRect(hwnd, &rect);
			render_state.width = rect.right - rect.left;
			render_state.height = rect.bottom - rect.top;

			int size = render_state.width * render_state.height * sizeof(unsigned int);

			if (render_state.memory)
				VirtualFree(render_state.memory, 0, MEM_RESERVE);
			render_state.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			render_state.bitmapinfo.bmiHeader.biSize = sizeof(render_state.bitmapinfo.bmiHeader);
			render_state.bitmapinfo.bmiHeader.biWidth = render_state.width;
			render_state.bitmapinfo.bmiHeader.biHeight = render_state.height;
			render_state.bitmapinfo.bmiHeader.biPlanes = 1;
			render_state.bitmapinfo.bmiHeader.biBitCount = 32;
			render_state.bitmapinfo.bmiHeader.biCompression = BI_RGB;

		}
		default:
		{
			 result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//Create Window class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = window_callback;

	//Create register class
	RegisterClass(&window_class);
	//Create Window
	HWND window = CreateWindow(window_class.lpszClassName, "First Window Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	HDC hdc = GetDC(window);

	Input input = {};



	float delta_time = 0.16666f;	
	LARGE_INTEGER frame_begin_time;
	QueryPerformanceCounter(&frame_begin_time);	//возвращает текущее значение счётчика таймера.
	float perfomance_frequency;
	{
		LARGE_INTEGER perf;
		QueryPerformanceFrequency(&perf);		//возвращает частоту таймера (число тиков в секунду).
		perfomance_frequency = static_cast<float>(perf.QuadPart);
	}

	int i = 0;
	while (running)
	{
		// Input
		MSG message;

		for (int i = 0; i < BUTTON_COUNT; i++)
		{
			input.buttons[i].changed = false;
		}

		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			switch (message.message)
			{
				case WM_KEYUP:
				case WM_KEYDOWN:
				{
					u32 vk_code = static_cast<u32>(message.wParam);
					bool isDown = ((message.lParam & (1 << 31)) == 0);
					
#define process_button(b, vk)\
case vk:{\
input.buttons[b].changed = isDown != input.buttons[b].isDown;\
input.buttons[b].isDown = isDown;\
} break;
					switch (vk_code)
					{
						process_button(BUTTON_UP, VK_UP);
						process_button(BUTTON_DOWN, VK_DOWN);
						process_button(BUTTON_W, 'W');
						process_button(BUTTON_S, 'S');
					}
				} break;
				default:
				{
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
			}

		}
		//Simulate
		drawBackground(i * 3);
		i++;
		SimulateGame(&input, delta_time);
		

		//
		//if (firstPlayer.GetScore() == 10)
		//{
		//	MessageBox(NULL, (LPCTSTR)"RIGHT WIN", "", MB_OK);
		//	
		//}
		//else if (secondPlayer.GetScore() == 10)
		//{
		//	MessageBox(NULL, (LPCTSTR)"LEFT WIN", "", MB_OK);
		//}
		
		
		//Render
		StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmapinfo, DIB_RGB_COLORS, SRCCOPY);


		LARGE_INTEGER frame_end_time;
		QueryPerformanceCounter(&frame_end_time);
		delta_time = (static_cast<float>(frame_end_time.QuadPart - frame_begin_time.QuadPart)) / perfomance_frequency;
		frame_begin_time = frame_end_time;
	}
}