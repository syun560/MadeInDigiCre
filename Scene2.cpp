#include "Scene2.h"
#include "Input.h"

static const char question[50]{
	"�ŉY�H�Ƒ�w�̉p��\�L�́H"
};

static const char answer[4][50]{
	"SCE","SIT", "SET", "SCP"
};

Scene2::Scene2() {
	AnswerNum = 1;
}

Scene2::~Scene2() {
	
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
		if (JudgeAnswer(ans)) BaseScene::Clear();
		else BaseScene::Miss();
	}
	return 0;
}

void Scene2::Draw() {
	DrawFormatString(40, 120, MyDx::WHITE, "%s", question);

	static const int ANSWER_Y = 300;
	static const int OFFSET = 50;
	DrawFormatString(MyDx::FMX / 2, ANSWER_Y - OFFSET, MyDx::WHITE, "[��] %s", answer[0]);
	DrawFormatString(MyDx::FMX / 2, ANSWER_Y + OFFSET, MyDx::WHITE, "[��] %s", answer[1]);
	DrawFormatString(MyDx::FMX / 2 + OFFSET, ANSWER_Y, MyDx::WHITE, "[��] %s", answer[2]);
	DrawFormatString(MyDx::FMX / 2 - OFFSET, ANSWER_Y, MyDx::WHITE, "[��] %s", answer[3]);
	BaseScene::Draw();
}