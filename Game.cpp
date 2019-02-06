#include "Game.h"

Game::Game() {
	scene = TITLE;
}

void Game::Update() {
	switch (scene) {
	case TITLE:
		if(title.Update() == 1) scene = MAIN;
		break;
	case MAIN:
		mainScene.Update();
		break;
	}
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