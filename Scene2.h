#pragma once
#include "MyDx.h"
#include "Ball.h"
#include "BaseScene.h"

class Scene2 : public BaseScene {
	int AnswerNum;
	bool JudgeAnswer(int answer);
public:
	Scene2();
	~Scene2();
	int Update();
	void Draw();
};