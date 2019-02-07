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
		else if(t == 1) {
			scene = MAIN;
			gameScene = new Scene1();
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