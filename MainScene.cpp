#include "MainScene.h"
#include "Input.h"

MainScene::MainScene() {
	ball[0].SetSpeed(0);
}

int MainScene::Update() {
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
			
		}
	}
	return 0;
}

void MainScene::Draw(){
	for (int i = 0; i < BALL_NUM; i++) {
		ball[i].Draw();
	}
}