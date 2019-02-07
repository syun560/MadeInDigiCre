#include "Scene2.h"
#include "Input.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

Scene2::Scene2() {
	ball[0].SetSpeed(0);
	for (int i = 0; i < IMG_MAX; ++i) {
		char filepass[100];
		sprintf_s(filepass, "dat/img/cat%02d.png", i + 1);
		img[i] = LoadGraph(filepass);
	}
	for (int i = 0; i < BALL_NUM; ++i) {
		ball[i].SetImg(img[GetRand(IMG_MAX -1)], 0.2);
	}
}

Scene2::~Scene2() {
	for (int i = 0; i < IMG_MAX; ++i) {
		DeleteGraph(img[i]);
	}
}

int Scene2::Update() {
	if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	if (Input::Key(KEY_INPUT_RIGHT) > 0) ball[0].Move(0.0);
	else if (Input::Key(KEY_INPUT_LEFT) > 0) ball[0].Move(DX_PI);
	else if (Input::Key(KEY_INPUT_DOWN) > 0) ball[0].Move(0.5 * DX_PI);
	else if (Input::Key(KEY_INPUT_UP) > 0) ball[0].Move(1.5 * DX_PI);
	else ball[0].SetSpeed(0);

	for (int i = 0; i < BALL_NUM; i++) {
		ball[i].Update();
	}
	for (int i = 1; i < BALL_NUM; i++) {
		if (ball[i].IsCollided(ball[0])) {
			// ƒ^ƒCƒgƒ‹‚É–ß‚é
			return -1;
		}
	}
	return 0;
}

void Scene2::Draw(){
	for (int i = 0; i < BALL_NUM; i++) {
		ball[i].Draw();
	}
}