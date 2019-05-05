#pragma once
#include "MyDx.h"

class Box {
	int x, y, color, fillflag;
	int width, height;
	int spd;
public:
	Box();
	int Update();
	void Draw();
};