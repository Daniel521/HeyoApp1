#include <Windows.h>
#include "Graphics.h"

#include "Level1.h"
#include "GameController.h"
#include "GameMemory.h"

// Ball struct
Ball ball;

// Graphics pointer
Graphics * graphics;

LRESULT CALLBACK WindowProc
(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
);

int WINAPI wWinMain
(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow
)
{
	/* Register Class */

	// Make class
	WNDCLASSEX wc;

	// Empty it
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// Fill it with some crap!
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = "Class 1";
	wc.style = CS_HREDRAW | CS_VREDRAW;

	// Register class
	RegisterClassEx(&wc);

	/* Create Window */

	// The rect for the client window size
	RECT rect = { 0, 0, 800, 600 };

	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, NULL, WS_EX_OVERLAPPEDWINDOW);

	// Create window and fill it
	HWND hWnd = CreateWindowEx
	(
		WS_EX_OVERLAPPEDWINDOW,
		"Class 1",
		"Heyo",
		WS_OVERLAPPEDWINDOW,
		50,
		50,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	// CHECK, if window was not created correctly
	if (!hWnd)
		return -1;

	/* Create Graphics */

	graphics = new Graphics;
	if (graphics->Init(hWnd) == false)
	{
		delete graphics;
		return -1;
	}

	/* Show Window */
	ShowWindow(hWnd, nCmdShow);

	/* Game Info */



	/* Message Loop */
	MSG message;
	message.message = WM_NULL;

	// Loop
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);

			DispatchMessage(&message);

		}
		else
		{
			// Update!
			


			// Render!
			graphics->BeginDraw();

			graphics->ClearScreen(.1, .8, .5);

			graphics->DrawCircle(ball.coordX, ball.coordY, 10, .75, .1, .9, 1);

			graphics->EndDraw();
		}
	}

	return message.wParam;
}


LRESULT CALLBACK WindowProc
(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
		break;
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
			case VK_LEFT:
			{
				ball.coordX+=2;
				break;
			}
			case VK_RIGHT:
			{
				ball.coordX+=2;
				break;
			}
			case VK_UP:
			{
				ball.coordY-=2;
				break;
			}
			case VK_DOWN:
			{
				ball.coordY+=2;
				break;
			}
		} break;
	}
	case WM_KEYUP:
	{
		switch (wParam)
		{
		case VK_LEFT:
		{
			break;
		}
		default:
			break;
		}break;
	}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}