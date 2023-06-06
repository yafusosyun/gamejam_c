#include "DrawRankingScene.h"

#include "PadInput.h"

#include "DxLib.h"

DrawRankingScene::DrawRankingScene(int sound) {
	ranking.ReadRanking();
	for (int i = 0; i < 5; i++) {
		bgm = sound;
		rankingData[i] = ranking.GetRankingData(i);
	}

	image = LoadGraph("Resources/images/Ranking.png");
	//TitleSE2 = LoadSoundMem("Resources/sounds/decision.wav");
}

AbstractScene* DrawRankingScene::Update() {
	return this;
}

void DrawRankingScene::Draw() const {
	DrawGraph(0, 0, image, TRUE);
	
	SetFontSize(60);
	DrawString(140, 100, "RANKING", 0x000000);

	SetFontSize(40);
	for (int i = 0; i < 5; i++) {
		DrawFormatString(92, 300 + 50 * i, 0x000000, "%d %4s ", rankingData[i].no, rankingData[i].name.c_str());
		DrawFormatString(390, 300 + 50 * i, 0x000000, "%5ld", rankingData[i].score);
	}

	SetFontSize(32);
	DrawString(280, 610, "A  PUSH", 0x000000);
}

//�V�[���̕ύX����
