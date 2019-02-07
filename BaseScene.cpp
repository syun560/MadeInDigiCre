#include "BaseScene.h"

BaseScene::BaseScene() {
	time = 60 * 5; // 60FPSの場合5秒
	state = PLAYING;
}

int BaseScene::Update() {
	if (state == PLAYING) time--;
	if (time == 0) {
		state = MISS;
	}
	return 0;
}

void BaseScene::Miss() {
	state = MISS;
}

void BaseScene::Clear() {
	state = CLEARED;
}

void BaseScene::Draw() {
	// カウントダウン
	DrawFormatString(0, 0, MyDx::WHITE, "%d", time/60);
	if (state != PLAYING) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
		DrawBox(50,50,MyDx::FMX-50,MyDx::FMY-50,MyDx::WHITE,TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if(state == CLEARED) DrawFormatString(100, 200, MyDx::GREEN, "Cleared");
		else if(state == MISS) DrawFormatString(100, 200, MyDx::RED, "MISS");
		DrawFormatString(100, 300, MyDx::WHITE, "Press ESC to title");
		DrawFormatString(100, 320, MyDx::WHITE, "Press R to retry");
	}
}