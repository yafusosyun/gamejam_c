#include"DxLib.h"
#include"GameMain.h"
#include"Timing.h"

Timing timing;

AbstractScene* GameMain::Update() {
	timing.Update();
	return this;
}

void GameMain::Draw() const {
	timing.Draw();
}
