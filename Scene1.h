#pragma once
#include "MyDx.h"
#include "Ball.h"
#include "BaseScene.h"

static const int BALL_NUM = 20;
static const int IMG_MAX = 15;

class Scene1 : public BaseScene {
	int img[IMG_MAX];
	Ball ball[BALL_NUM];
public:
	Scene1();
	~Scene1();
	int Update();
	void Draw();
};