#include "Scene3.h"
#include <math.h>
#include "Input.h"

Scene3::Scene3() {
	powder_num = 1000;
	p = new Powder[powder_num];
	for (int i = 0; i < powder_num; i++) {
		p[i].x = GetRand(MyDx::FMX);
		p[i].y = GetRand(MyDx::FMY);
		p[i].flag = false;
	}

	box_num = 50;
	box = new Box[box_num];

	PlayMusic("dat/music/tw103.mp3", DX_PLAYTYPE_BACK);
	cnt = 0;
}

Scene3::~Scene3() {
	delete [] p;
	StopMusic();
}

int Scene3::Update(){
	if (Input::MouseL() > 0) {
		
	}
	if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	cnt++;
	textBox.Update();
	for (int i = 0; i < box_num; i++) {
		box[i].Update();
	}
	return 0;
}

void Scene3::Draw() {
	textBox.Draw();
	for (int i = 0; i < powder_num; i++) {
		DrawPixel(p[i].x, p[i].y, MyDx::GetRandColor());
	}
	for (int i = 0; i < box_num; i++) {
		box[i].Draw();
	}
}