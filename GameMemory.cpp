#include "GameMemory.h"

Ball::Ball(Graphics * gfx)
{
	coordX = 400;
	coordY = 300;
	moveX = no;
	moveY = no;

	sprites = new SpriteSheet(L"test.png", gfx);
};

void Ball::resetBall()
{
	coordX = 400;
	coordY = 300;
}

