#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <Windows.h>
#include <d2d1.h>

// Graphics class :D
class Graphics
{
private:
	// com interfaces
	ID2D1Factory * factory;
	ID2D1HwndRenderTarget * renderTarget;
	ID2D1SolidColorBrush * brush;
public:
	// constructor | desctructor
	Graphics();
	~Graphics();

	//// This function runs once in main to initialize the interfaces with the necessary values
	bool Init(HWND windowHandle);

	// Our drawing functions?
	void BeginDraw()
	{
		renderTarget->BeginDraw();
	}

	void EndDraw()
	{
		renderTarget->EndDraw();
	}

	// to clear screen to a certain color
	void ClearScreen(float r, float g, float b);

	// to draw a circle
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);

};

#endif //!GRAPHICS_H
