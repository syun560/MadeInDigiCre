#pragma once
#include "MyDx.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Title.h"

class Game {
	enum Scene {
		TITLE, MAIN,
	};
	BaseScene* gameScene;
	Title title;
	Scene scene;
public:
	Game();
	int Update();
	void Draw();
};