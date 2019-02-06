#include "Ball.h"

Ball::Ball() {
	vx = vy = 0.0;
	x = GetRand(MyDx::FMX);
	y = GetRand(MyDx::FMY);
	ang = DX_PI * 2.0 * GetRand(1000) / 1000.0;
	spd = 3.0;
	r = 10.0;
	col = MyDx::GetRandColor();
	useGravity = useAirResist = false;
	useBounce = true;
}

Ball::Ball(double dx, double dy, double dr) {
	x = dx; y = dy; r = dr;
	vx = vy = 0.0;
	ang = DX_PI * 2.0 * GetRand(1000) / 1000.0;
	spd = 1.0;
	useGravity = useAirResist = false;
	useBounce = true;
}

bool Ball::IsCollided(const Ball& dball) const{
	if ((x - dball.x)*(x - dball.x) + (y - dball.y)*(y - dball.y) < (dball.r + r)*(dball.r + r)) return true;
	else return false;
}

void Ball::Update() {
	if (useAirResist) {
		spd -= spd * 0.02;
	}
	vx = spd * cos(ang);
	vy = spd * sin(ang);
	if (useGravity) vy += 0.001;
	x += vx;
	y += vy;
	if ((x < 0 || x > MyDx::FMX) && useBounce) vx *= -1.0;
	if ((y < 0 || y > MyDx::FMY) && useBounce) vy *= -1.0;
	ang = atan2(vy, vx);
}

void Ball::Draw(int img) const{
	//if (img == 0) DrawCircleAA((float)x, (float)y, (float)r, 100, col, TRUE);
	if (img == 0) DrawCircle((int)x, (int)y, (int)r, col, TRUE);
	else DrawRotaGraphF((float)x, (float)y, r * 0.05, 0.0, img, TRUE);
}

void Ball::SetSpeed(int speed) {
	spd = speed;
}

void Ball::Move(double angle) {
	ang = angle;
	spd = 5.0;
}