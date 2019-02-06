#pragma once
#include "MyDx.h"
#include "Ball.h"
#define BALL_NUM 20

class MainScene {
	int img;
	Ball ball[BALL_NUM];
public:
	MainScene();
	int Update();
	void Draw();
};