#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include "Graphics.h"

class GameLevel
{
private:

public:
	bool Loading;

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render(Graphics * gfx) = 0;
	virtual void Update() = 0;

};

#endif