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

AbstractScene* Result::Update() {	//�`��ȊO�̍X�V�E�ϐ��̒l�̏������E�O�̉�ʂւ̏㏑��
	if (flg) {
		Score = Score1 * Comp;
		Score = Score / 100;
		flg = false;
	}

	if (PadInput::OnClick(XINPUT_BUTTON_A)) {	//�����AA�L�[�������ꂽ��
		rank.ReadRanking();
		if (Ranking::GetRankingData(4).score < Score) {
			return new InputRankingScene(Score);
		}
		else {
			return new DrawRankingScene(Score);
		}
						
	}
	return this;								//����ȊO�Ȃ炱�̃V�[����`�悵������
}

void Result::Draw()const		//�`��Ɋւ��邱�Ƃ���
{
	DrawGraph(0, 0, ResultImg, TRUE);
	SetFontSize(100);
	DrawString(400, 100, "���U���g", 0x000000);
	SetFontSize(50);
	DrawFormatString(450, 230, GetColor(255, 255, 255), "�X�R�A:%d",Score1);
	DrawFormatString(450, 280, GetColor(255, 255, 255), "�����x:%d%%",Comp);
	DrawFormatString(350, 330, GetColor(255, 255, 255), "�������_:%d �~ %d%% = %d�_", Score1, Comp, Score);

	DrawFormatString(350, 400, GetColor(255, 255, 255), "-- A�{�^���Ń����L���O�� --");
}

void Result::getResult(int score, int comp) {
	score = Score;
	comp = Comp;
}