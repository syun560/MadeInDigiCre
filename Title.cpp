#include "Title.h"
#include "Input.h"

Title::Title() {
	selectmode = 0;
	selectgame = -1;
}

int Title::Update() {
	if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	if (selectgame == -1) {
		if (Input::Key(KEY_INPUT_DOWN) == 1) selectmode = 1;
		if (Input::Key(KEY_INPUT_UP) == 1) selectmode = 0;
	}
	else {
		if (Input::Key(KEY_INPUT_DOWN) == 1) selectgame = 1;
		if (Input::Key(KEY_INPUT_UP) == 1) selectgame = 0;
	}

	if (selectmode == 1) {
		if (selectgame == -1) {
			if (Input::Key(KEY_INPUT_Z) == 1 || Input::Key(KEY_INPUT_RIGHT) == 1) selectgame = 0;
		}
		else {
			if (Input::Key(KEY_INPUT_X) == 1 || Input::Key(KEY_INPUT_LEFT) == 1) selectgame = -1;
			if (Input::Key(KEY_INPUT_Z) == 1) return selectgame+1;
		}
		
	}
	return 0;
}

void Title::Draw() {
	static const int LIST_X = 80;
	static const int LIST_Y = 100;
	static const int LIST_WIDTH = 150;
	DrawFormatString(30, 40, MyDx::WHITE, "Title");
	DrawFormatString(LIST_X, LIST_Y, MyDx::WHITE, "Start");
	DrawFormatString(LIST_X, LIST_Y + 20, MyDx::WHITE, "Select Scene");
	DrawBox(LIST_X, LIST_Y + selectmode * 20, LIST_X + LIST_WIDTH, LIST_Y + (selectmode + 1) * 20, MyDx::YELLOW, FALSE);
	if (selectgame != -1) {
		static int LIST2_X = LIST_X + LIST_WIDTH;
		static int LIST2_Y = LIST_Y + 20;
		DrawFormatString(LIST2_X, LIST2_Y, MyDx::WHITE, "game1");
		DrawFormatString(LIST2_X, LIST2_Y + 20, MyDx::WHITE, "game2");
		DrawBox(LIST2_X, LIST2_Y + selectgame* 20, LIST2_X + LIST_WIDTH, LIST2_Y + (selectgame + 1) * 20, MyDx::YELLOW, FALSE);
	}
	DrawFormatString(1, 1, MyDx::WHITE, "mode = %d, game = %d", selectmode, selectgame);
}