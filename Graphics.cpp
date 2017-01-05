#include "Graphics.h"

// Constructor
// Make sure there is nothing in them initially
Graphics::Graphics()
{
	factory = NULL;
	renderTarget = NULL;
	brush = NULL;
}


// Destructor
// Make sure they are released if they were used
Graphics::~Graphics()
{
	if (factory)
		factory->Release();
	if (renderTarget)
		renderTarget->Release();
	if (brush)
		brush->Release();
}

bool Graphics::Init(HWND windowHandle)
{
	// our little checker variable to see if we were able to do it all right

	// make the factory
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);

	// make sure it worked
	if (res != S_OK)
		return false;

	// time for the render target

	// first check the client size
	RECT rect;
	GetClientRect(windowHandle, &rect);

	// makes the renderTarget, has to be done from factory apperantly
	res = factory->CreateHwndRenderTarget
	(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget
	);

	//CHECK
	if (res != S_OK)
		return false;

	// now for the brush
	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f), &brush);

	//CHECK
	if (res != S_OK)
		return false;


	// if all went well, return true
	return true;
}

void Graphics::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float xCenter, float yCenter, float radius, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));

	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(xCenter, yCenter), radius, radius), brush, 3.0f);
}