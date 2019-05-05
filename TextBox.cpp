#include "TextBox.h"

TextBox::TextBox() {
	margin = 30;
	height = 100;
	padding = 20;
	color = MyDx::BLUE;

	x1 = margin;
	y1 = MyDx::FMY - margin - height;
	x2 = MyDx::FMX - margin;
	y2 = MyDx::FMY - margin;
}

void TextBox::Update() {

}

void TextBox::Draw() {
	DrawBox(x1, y1, x2, y2, color, FALSE);
	DrawFormatString(x1 + padding, y1 + padding, MyDx::WHITE, "–l‚½‚¿‚ÍŽ©—R‚¾");
}