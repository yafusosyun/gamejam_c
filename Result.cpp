#include"DxLib.h"
#include"Result.h"
#include"GameMain.h"
#include"Ranking.h"
#include"PadInput.h"
#include"InputRankingScene.h"
#include"DrawRankingScene.h"

Ranking rank;

Result::Result(int score, int comp) {
	Score = score;
	Score1 = score;
	Comp = comp;
	flg = true;
	ResultImg = LoadGraph("images/GameMain.png");
};

AbstractScene* Result::Update() {	//描画以外の更新・変数の値の初期化・前の画面への上書き
	if (flg) {
		Score = Score1 * Comp;
		Score = Score / 100;
		flg = false;
	}

	if (PadInput::OnClick(XINPUT_BUTTON_A)) {	//もし、Aキーが押されたら
		rank.ReadRanking();
		if (Ranking::GetRankingData(4).score < Score) {
			return new InputRankingScene(Score);
		}
		else {
			return new DrawRankingScene(Score);
		}
						
	}
	return this;								//それ以外ならこのシーンを描画し続ける
}

void Result::Draw()const		//描画に関することだけ
{
	DrawGraph(0, 0, ResultImg, TRUE);
	SetFontSize(100);
	DrawString(400, 100, "リザルト", 0x000000);
	SetFontSize(50);
	DrawFormatString(450, 230, GetColor(255, 255, 255), "スコア:%d",Score1);
	DrawFormatString(450, 280, GetColor(255, 255, 255), "完成度:%d%%",Comp);
	DrawFormatString(350, 330, GetColor(255, 255, 255), "総合得点:%d × %d%% = %d点", Score1, Comp, Score);

	DrawFormatString(350, 400, GetColor(255, 255, 255), "-- Aボタンでランキングへ --");
}

void Result::getResult(int score, int comp) {
	score = Score;
	comp = Comp;
}