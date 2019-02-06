#include "Game.h"

Game::Game() {
	scene = TITLE;
}

int Game::Update() {
	switch (scene) {
	case TITLE:
		if(title.Update() == 1) scene = MAIN;
		else if (title.Update() == -1) return -1;
		break;
	case MAIN:
		if(mainScene.Update() == -1) scene = TITLE;
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
		mainScene.Draw();
		break;
	}
}