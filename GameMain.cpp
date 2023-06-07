#include"DxLib.h"
#include"GameMain.h"
#include"Timing.h"
#include"UI.h"
#include"PadInput.h"
#include"nail.h"

Timing timing;
UI ui;
Nail nail;

AbstractScene* GameMain::Update() {
	timing.Update();
	ui.CountDown();
	if (Timing::GetButtonFlg() == true ) {
			ui.Score();
			nail.SetNailCount();
	}
	nail.Update();
	if (flg) {
		nail.LoadImages();
		flg = false;
	}
	return this;
}

void GameMain::Draw() const {
	timing.Draw();
	ui.DrawScore();
	ui.DrawCountDown();
	nail.nail();
}
