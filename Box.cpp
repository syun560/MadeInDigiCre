#include "Box.h"

Box::Box() {
	x = MyDx::FMX + GetRand(100);
	y = 300 + GetRand(50);
	width = 50 + GetRand(100);
	height = 200;
	// color = MyDx::WHITE;
	color = MyDx::GetRandColor();
	fillflag = FALSE;
	spd = 3 + GetRand(5);
}

int Box::Update() {
	x -= spd;
	if (x + width < 0) x += MyDx::FMX + width;
	return 0;
}

void Box::Draw() {
	DrawBox(x, y, x + width, y + height, color, fillflag);
}