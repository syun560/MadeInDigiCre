#include "Scene2.h"
#include "Input.h"

static const char question[50]{
	"é≈âYçHã∆ëÂäwÇÃâpåÍï\ãLÇÕÅH"
};

static const char answer[4][50]{
	"SCE","SIT", "SET", "SCP"
};

Scene2::Scene2() {
	AnswerNum = 1;
	se = LoadSoundMem("dat/se/correct1.mp3");
	correct = false;
}

Scene2::~Scene2() {
	DeleteSoundMem(se);
}

bool Scene2::JudgeAnswer(int answer) {
	if (answer == AnswerNum) return true;
	else return false;
}

int Scene2::Update() {
	if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	if (Input::Key(KEY_INPUT_R) == 1) return -2;
	BaseScene::Update();

	int ans = -1;
	if (Input::Key(KEY_INPUT_UP) == 1) ans = 0;
	if (Input::Key(KEY_INPUT_DOWN) == 1) ans = 1;
	if (Input::Key(KEY_INPUT_RIGHT) == 1) ans = 2;
	if (Input::Key(KEY_INPUT_LEFT) == 1) ans = 3;
	if (ans != -1) {
		if (JudgeAnswer(ans)) {
			BaseScene::Clear();
			PlaySoundMem(se, DX_PLAYTYPE_BACK);
			correct = true;
		}
		else BaseScene::Miss();
	}
	return 0;
}

void Scene2::Draw() {
	DrawFormatString(40, 120, MyDx::WHITE, "%s", question);

	static const int ANSWER_Y = 300;
	static const int OFFSET = 50;
	DrawFormatString(MyDx::FMX / 2, ANSWER_Y - OFFSET, MyDx::WHITE, "[Å™] %s", answer[0]);
	DrawFormatString(MyDx::FMX / 2, ANSWER_Y + OFFSET, MyDx::WHITE, "[Å´] %s", answer[1]);
	DrawFormatString(MyDx::FMX / 2 + OFFSET, ANSWER_Y, MyDx::WHITE, "[Å®] %s", answer[2]);
	DrawFormatString(MyDx::FMX / 2 - OFFSET, ANSWER_Y, MyDx::WHITE, "[Å©] %s", answer[3]);
	
	if (correct) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);
		DrawCircle(MyDx::FMX / 2, ANSWER_Y, 50, MyDx::RED, FALSE, 10);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	
	BaseScene::Draw();
}