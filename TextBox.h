#pragma once
#include "MyDx.h"

class TextBox {
	int height, margin, padding;
	int x1, y1, x2, y2;
	int color;
public:
	TextBox();
	void Update();
	void Draw();
};