#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameLevel.h"
#include "Graphics.h"

class GameController
{
private:
	GameController() { }
	static GameLevel * currentLevel;
public:
	static bool Loading;

	static void Init();

	static void LoadInitialLevel(GameLevel * lev);
	static void SwitchLevel(GameLevel * lev);

	static void Render(Graphics * gfx);
	static void Update();
};


#endif // !GAMECONTROLLER_H


