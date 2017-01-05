#ifndef GAMEMEMORY_H
#define GAMEMEMORY_H

struct Ball
{
	enum move {
		no, left, right, up, down
	};
public:
	// Position of the ball
	float coordX;
	float coordY;

	// Is the ball moving?
	int moveX;
	int moveY;

	Ball();

	void resetBall();
};

#endif // !GAMEMEMORY_H