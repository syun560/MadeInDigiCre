#pragma once
#include "MyDx.h"
#include "math.h"

class Ball {
	double x, y, vx, vy, ang, spd, r;
	bool useGravity, useAirResist, useBounce;
	int col;
public:
	Ball();
	Ball(double x, double y, double r);
	void Update();
	void Draw(int img=0) const;
	bool IsCollided(const Ball&) const;

	void Move(double angle);
	void SetSpeed(int speed);
};