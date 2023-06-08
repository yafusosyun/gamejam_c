#include"DxLib.h"
#include"GameMain.h"
#include"Timing.h"
#include"UI.h"
#include"PadInput.h"
#include"nail.h"
#include"Result.h"
#include"HammerAnimation.h"


Timing timing;
UI ui;
Nail nail;
bool f = false;

GameMain::GameMain() {
	timing.Init();
	ui.Init();
	nail.Init();
	HammerAnimation::AnimInit();
	MainImg = LoadGraph("images/GameMain.png");
}

AbstractScene* GameMain::Update() {
	
	timing.Update();

	ui.CountDown();
	if (Timing::GetButtonFlg() == true ) {
			ui.Score();
			nail.SetNailCount();
			f = true;
	}
	if (f) {
		f = HammerAnimation::SelectAnimation(timing.GetJudge(), Direction::Right);
	}
	nail.Update();
	if (flg) {
		nail.LoadImages();
		flg = false;
	}
	
	if (ui.gWaitTime <= 0)
	{
		return new Result(ui.gScore, timing.GetComp());
	}

	return this;
}

void GameMain::Draw() const {
	DrawGraph(-100, 0, MainImg, FALSE);
	DrawBox(950, 0, 1280, 720, 0x000000, TRUE);
	DrawString(20, 650, "Bボタンでハンマーを振る", 0xff0000);
	timing.Draw();
	ui.DrawScore();
	ui.DrawCountDown();
	nail.nail();
	HammerAnimation::DrawHammer(400, 300);

}
