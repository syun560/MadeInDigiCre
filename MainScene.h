#pragma once
#include "MyDx.h"
#include "Ball.h"
#include "BaseScene.h"

#define BALL_NUM 20

class MainScene : public BaseScene {
	int img;
	Ball ball[BALL_NUM];
public:
	MainScene();
	int Update();
	void Draw();
};