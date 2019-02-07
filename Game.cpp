#include "Game.h"

Game::Game() {
	scene = TITLE;
}

int Game::Update() {
	int t;
	switch (scene) {
	case TITLE:
		t = title.Update();
		if (t == -1) return -1;
		else if (t == 0) return 0;
		else {
			scene = MAIN;
			if(t = 1) gameScene = new Scene1();
			else if (t = 2) gameScene = new Scene2();
			else if (t = 3) gameScene = new Scene3();
		}
		break;
	case MAIN:
		if (gameScene->Update() == -1) {
			delete gameScene;
			scene = TITLE;
		}
		break;
	}
	return 0;
}

void Game::Draw() {
	switch (scene) {
	case TITLE:
		title.Draw();
		break;
	case MAIN:
		gameScene->Draw();
		break;
	}
}