#include "GameMemory.h"

Ball::Ball()
{
	coordX = 400;
	coordY = 300;
	moveX = no;
	moveY = no;
};

void Ball::resetBall()
{
	coordX = 400;
	coordY = 300;
}