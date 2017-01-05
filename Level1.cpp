/*

#include "GameController.h"
#include "Level1.h"
#include "Graphics.h"


void Level1::Load()
{
	y = ySpeed = 0.0f;
}

void Level1::Unload()
{

}

void Level1::Render(Graphics * gfx)
{
	gfx->ClearScreen(0, 0, .5f);
	gfx->DrawCircle(
		375.0f, y, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f
	);
}

void Level1::Update()
{
	ySpeed += 1.0f;
	y += ySpeed;
	if (y > 600)
	{
		y = 600;
		ySpeed = -30.0f;
	}
}

*/