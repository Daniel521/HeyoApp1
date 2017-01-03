#ifndef LEVEL1_H
#define LEVEL1_H

#include "GameLevel.h"

class Level1 : public GameLevel
{
private:
	float y = 0.0;
	float ySpeed = 0.0f;
public:
	void Load() override;
	void Unload() override;
	void Render(Graphics * gfx) override;
	void Update() override;
};

#endif // !LEVEL1_H

