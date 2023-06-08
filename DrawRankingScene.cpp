#include "DrawRankingScene.h"
#include "PadInput.h"
#include "DxLib.h"
#include "Title.h"

DrawRankingScene::DrawRankingScene(int _score) {
	ranking.ReadRanking();
	for (int i = 0; i < 5; i++) {
		
		rankingData[i] = ranking.GetRankingData(i);
	}

	image = LoadGraph("images/GameMain.png");
}

AbstractScene* DrawRankingScene::Update() {
	if (PadInput::OnClick(XINPUT_BUTTON_A) == 1) {
		return new Title();
	}
	return this;
}

void DrawRankingScene::Draw() const {
	DrawGraph(0, 0, image, TRUE);
	
	SetFontSize(60);
	DrawString(140, 100, "RANKING", 0x000000);

	SetFontSize(40);
	for (int i = 0; i < 5; i++) {
		DrawFormatString(92, 250 + 50 * i, 0x000000, "%d %4s ", rankingData[i].no, rankingData[i].name.c_str());
		DrawFormatString(390, 250 + 50 * i, 0x000000, "%5ld", rankingData[i].score);
	}

	SetFontSize(32);
	DrawString(280, 610, "Aƒ{ƒ^ƒ“‚Å–ß‚é", 0x000000);
}

