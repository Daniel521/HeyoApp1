#ifndef GAMEMEMORY_H
#define GAMEMEMORY_H

#include "SpriteSheet.h"
#include "Graphics.h"



struct Ball
{
	enum move {
		no, left, right, up, down
	};
public:

	SpriteSheet * sprites;


	// Position of the ball
	float coordX;
	float coordY;

	// Is the ball moving?
	int moveX;
	int moveY;

	Ball(Graphics * gfx);

	~Ball()
	{
		delete sprites;
	}


	void resetBall();
};

#endif // !GAMEMEMORY_H