#include "Scene1.h"
#include "Input.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

Scene1::Scene1() {
	// ÉçÅ[Éh
	img[0] = LoadGraph("dat/img/fish_sakana_sake.png");
	for (int i = 1; i < IMG_MAX; ++i) {
		char filepass[100];
		sprintf_s(filepass, "dat/img/cat%02d.png", i);
		img[i] = LoadGraph(filepass);
	}
	bg = LoadGraph("dat/img/bg_ground.png");

	// èâä˙âª
	ball[0].SetImg(img[0], 0.1);
	ball[0].SetPos(MyDx::FMX + 20, MyDx::FMY/2);
	ball[0].SetSpeed(0);
	for (int i = 1; i < BALL_NUM; ++i) {
		ball[i].SetImg(img[1 + GetRand(IMG_MAX -2)], 0.2);
		ball[i].SetSpeed(1 + GetRand(2));
	}
}

Scene1::~Scene1() {
	for (int i = 0; i < IMG_MAX; ++i) {
		DeleteGraph(img[i]);
	}
	DeleteGraph(bg);
}

int Scene1::Update() {
	if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	if (Input::Key(KEY_INPUT_R) == 1) return -2;
	BaseScene::Update();
	if (Input::Key(KEY_INPUT_RIGHT) > 0) ball[0].Move(0.0);
	else if (Input::Key(KEY_INPUT_LEFT) > 0) ball[0].Move(DX_PI);
	else if (Input::Key(KEY_INPUT_DOWN) > 0) ball[0].Move(0.5 * DX_PI);
	else if (Input::Key(KEY_INPUT_UP) > 0) ball[0].Move(1.5 * DX_PI);
	else ball[0].SetSpeed(0);

	if (ball[0].GetX() < 0) BaseScene::Clear();
	for (int i = 0; i < BALL_NUM; i++) {
		ball[i].Update();
	}
	for (int i = 1; i < BALL_NUM; i++) {
		if (ball[i].IsCollided(ball[0])) {
			BaseScene::Miss();
		}
	}
	return 0;
}

void Scene1::Draw(){
	DrawGraph(0, 0, bg, TRUE);
	for (int i = 0; i < BALL_NUM; i++) {
		ball[i].Draw();
	}
	BaseScene::Draw();
}