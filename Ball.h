#pragma once
#include "MyDx.h"
#include "math.h"

class Ball {
	double x, y, vx, vy, ang, spd, r;
	bool useGravity, useAirResist, useBounce;
	int col, img;
	double size;
public:
	Ball();
	void Update();
	void Draw() const;
	bool IsCollided(const Ball&) const;

	void Move(double angle);
	void SetSpeed(int speed);
	void SetImg(int handle, double size=1.0);
	void SetPos(int x, int y);

	int GetX();
};