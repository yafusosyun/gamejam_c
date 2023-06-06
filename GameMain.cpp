#include"DxLib.h"
#include"GameMain.h"
#include"Timing.h"
#include"UI.h"
#include"PadInput.h"

Timing timing;
UI ui;

AbstractScene* GameMain::Update() {
	timing.Update();
	if (PadInput::OnClick(XINPUT_BUTTON_A)) {
		ui.Score();
	}

	return this;
}

void GameMain::Draw() const {
	timing.Draw();
	ui.DrawScore();
}
