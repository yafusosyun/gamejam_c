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

	
}

AbstractScene* InputRankingScene::Update() {
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_UP) == 1) {
		//PlaySoundMem(TitleSE, DX_PLAYTYPE_BACK);
		if (--cursorPoint.y < 0) {
			//PlaySoundMem(TitleSE, DX_PLAYTYPE_BACK);
			if (cursorPoint.x > 10) {
				cursorPoint.y = 3;
			}
			else {
				cursorPoint.y = 4;
			}
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_DOWN) == 1) {
		//PlaySoundMem(TitleSE, DX_PLAYTYPE_BACK);
		if (++cursorPoint.y > 3 && cursorPoint.x > 10 || cursorPoint.y > 4) {
			cursorPoint.y = 0;
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_RIGHT) == 1) {
		//PlaySoundMem(TitleSE, DX_PLAYTYPE_BACK);
		if (++cursorPoint.x > 10 && cursorPoint.y > 3 || cursorPoint.x > 12) {
			cursorPoint.x = 0;
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_DPAD_LEFT) == 1) {
		//PlaySoundMem(TitleSE, DX_PLAYTYPE_BACK);
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
		//PlaySoundMem(TitleSE2, DX_PLAYTYPE_BACK);
		if (keyboard[cursorPoint.y][cursorPoint.x] == '<') {
			if (name.size() > 0) {
				name.erase(name.begin() + (name.size() - 1));
			}
		}
		else {
			name += keyboard[cursorPoint.y][cursorPoint.x];
		}
	}
	if (PadInput::OnClick(XINPUT_BUTTON_B) == 1) {
		
			ranking.WriteRanking(name, score);
			
			return new DrawRankingScene(score);
		
	}
	return this;
}

void InputRankingScene::Draw() const {
	DrawGraph(0, 0, image, TRUE);
	SetFontSize(80);
	DrawString(120, 100, "INPUT RANKING", 0xffffff);

	SetFontSize(48);
	DrawBox(420, 240, 860, 300, 0xffffff, TRUE);
	DrawFormatString(420, 250, 0xFF00FF, "%s", name.c_str());

	DrawBox(318 + 50 * cursorPoint.x, 360 + 50 * cursorPoint.y,
		368 + 50 * cursorPoint.x, 405 + 50 * cursorPoint.y, 0x808080, TRUE);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 14; j++) {
			DrawFormatString(j * 50 + 318, i * 50 + 355, 0xffffff, "%c", keyboard[i][j]);
		}
	}

	SetFontSize(32);
	DrawString(435, 640, "B BUTTON PUSH", 0xffffff);
}

//�V�[���̕ύX����
