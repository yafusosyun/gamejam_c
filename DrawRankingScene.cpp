#include "DrawRankingScene.h"
#include "PadInput.h"
#include "DxLib.h"
#include "Title.h"

DrawRankingScene::DrawRankingScene(int _score) {
	ranking.ReadRanking();
	for (int i = 0; i < 5; i++) {
		
		rankingData[i] = ranking.GetRankingData(i);
	}

	image = LoadGraph("Resources/images/Ranking.png");
	//TitleSE2 = LoadSoundMem("Resources/sounds/decision.wav");
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
	DrawString(140, 100, "RANKING", 0xffffff);

	SetFontSize(40);
	for (int i = 0; i < 5; i++) {
		DrawFormatString(92, 300 + 50 * i, 0xffffff, "%d %4s ", rankingData[i].no, rankingData[i].name.c_str());
		DrawFormatString(390, 300 + 50 * i, 0xffffff, "%5ld", rankingData[i].score);
	}

	SetFontSize(32);
	DrawString(280, 610, "A  PUSH", 0xffffff);
}

//�V�[���̕ύX����
