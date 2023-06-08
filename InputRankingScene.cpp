#include "InputRankingScene.h"
#include "DrawRankingScene.h"
#include "PadInput.h"

InputRankingScene::InputRankingScene(int _score) {
	score = _score;
	cursorPoint = { 0, 0 };
	ranking.ReadRanking();
	for (int i = 0; i < 5; i++) {
		rankingData[i] = ranking.GetRankingData(i);
	}
	image = LoadGraph("images/GameMain.png");
	cursorSE = LoadSoundMem("SE/cursor.mp3");
	decisionSE = LoadSoundMem("SE/decision.mp3");
	
}

AbstractScene* InputRankingScene::Update() {
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_UP) == 1 || (PadInput::GetFlgY() == 0 && MARGIN < PadInput::GetPadThumbLY())) {
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		if (--cursorPoint.y < 0) {
			if (cursorPoint.x > 10) {
				cursorPoint.y = 3;
			}
			else {
				cursorPoint.y = 4;
			}
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_DOWN) == 1  || (PadInput::GetFlgY() == 0 && PadInput::GetPadThumbLY() < -MARGIN)) {
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		if (++cursorPoint.y > 3 && cursorPoint.x > 10 || cursorPoint.y > 4) {
			cursorPoint.y = 0;
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_RIGHT) == 1 || (PadInput::GetFlgX() == 0 && MARGIN < PadInput::GetPadThumbLX())) {
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		if (++cursorPoint.x > 10 && cursorPoint.y > 3 || cursorPoint.x > 12) {
			cursorPoint.x = 0;
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_LEFT) == 1 || (PadInput::GetFlgX() == 0 && PadInput::GetPadThumbLX() < -MARGIN)) {
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		if (--cursorPoint.x < 0) {
			if (cursorPoint.y > 3) {
				cursorPoint.x = 10;
			}
			else {
				cursorPoint.x = 12;
			}
		}
	}

	if (PadInput::OnClick(XINPUT_BUTTON_A) == 1 && (name.size() < 5 || keyboard[cursorPoint.y][cursorPoint.x] == '<')) {
		PlaySoundMem(decisionSE, DX_PLAYTYPE_BACK);
		if (keyboard[cursorPoint.y][cursorPoint.x] == '<') {
			if (name.size() > 0) {
				name.erase(name.begin() + (name.size() - 1));
			}
		}
		else {
			name += keyboard[cursorPoint.y][cursorPoint.x];
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_B) == 1 && name.size() > 0) {
		PlaySoundMem(decisionSE, DX_PLAYTYPE_BACK);
		ranking.WriteRanking(name, score);
			
		return new DrawRankingScene(score);
		
	}
	return this;
}

void InputRankingScene::Draw() const {
	DrawGraph(0, 0, image, TRUE);
	SetFontSize(80);
	DrawString(450, 100, "名前入力", 0x000000);

	DrawBox(310, 350, 970, 610, 0xffffff, TRUE);

	SetFontSize(48);
	DrawBox(420, 240, 860, 300, 0xffffff, TRUE);
	DrawFormatString(420, 250, 0x000000, "%s", name.c_str());

	DrawBox(318 + 50 * cursorPoint.x, 360 + 50 * cursorPoint.y,
		368 + 50 * cursorPoint.x, 405 + 50 * cursorPoint.y, 0x808080, TRUE);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 14; j++) {
			DrawFormatString(j * 50 + 318, i * 50 + 355, 0x000000, "%c", keyboard[i][j]);
		}
	}

	SetFontSize(32);
	DrawString(400, 650, "Aボタンで選択　Bボタンで確定", 0x000000);
}
