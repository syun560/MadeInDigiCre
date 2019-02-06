#pragma once
#include "MyDx.h"
#include "MainScene.h"
#include "Title.h"

class Game {
	enum Scene {
		TITLE, MAIN,
	};
	MainScene mainScene;
	Title title;
	Scene scene;
public:
	Game();
	int Update();
	void Draw();
};