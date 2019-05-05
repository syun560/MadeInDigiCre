#pragma once
#include "MyDx.h"
#include "Box.h"
#include "BaseScene.h"
#include "TextBox.h"

struct Powder {
	int x, y;
	int color;
	bool flag;
};

class Scene3 : public BaseScene {
	Powder* p;
	TextBox textBox;
	Box* box;
	int powder_num;
	int box_num;
	int cnt;
	int x, y;
public:
	Scene3();
	~Scene3();
	int Update();
	void Draw();
};