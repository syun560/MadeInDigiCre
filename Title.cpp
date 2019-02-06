#include "Title.h"
#include "Input.h"

Title::Title() {

}

int Title::Update() {
	if (Input::Key(KEY_INPUT_RETURN) == 1) return 1;
	return 0;
}

void Title::Draw() {
	DrawFormatString(30,MyDx::FMY/2,MyDx::WHITE,"ƒ^ƒCƒgƒ‹");
}