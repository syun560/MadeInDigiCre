#pragma once
#include "MyDx.h"
#include "Ball.h"
#include "BaseScene.h"

class Scene2 : public BaseScene {
	static const int BALL_NUM = 20;
	static const int IMG_MAX = 15;
	int img[IMG_MAX];
	Ball ball[BALL_NUM];
public:
	Scene2();
	~Scene2();
	int Update();
	void Draw();
};