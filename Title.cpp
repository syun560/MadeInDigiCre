#include "Title.h"
#include "Input.h"

Title::Title() {
	select = 0;
}

int Title::Update() {
	if (select == 1 && Input::Key(KEY_INPUT_Z) == 1) return 1;
	if (Input::Key(KEY_INPUT_DOWN) == 1) select = 1;
	if (Input::Key(KEY_INPUT_UP) == 1) select = 0;
	if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	return 0;
}

void Title::Draw() {
	static const int LIST_X = 80;
	static const int LIST_Y = 100;
	DrawFormatString(30, 40, MyDx::WHITE, "Title");
	DrawFormatString(LIST_X, LIST_Y, MyDx::WHITE, "Start");
	DrawFormatString(LIST_X, LIST_Y + 20, MyDx::WHITE, "Select Scene");
	DrawBox(LIST_X, LIST_Y + select * 20, LIST_X + 150, LIST_Y + (select + 1) * 20, MyDx::YELLOW, FALSE);
}