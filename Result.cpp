#include"DxLib.h"
#include"Result.h"
#include"GameMain.h"
#include"Ranking.h"
#include"PadInput.h"
#include"InputRankingScene.h"
#include"DrawRankingScene.h"

Ranking rank;

Result::Result(int score, int time) {
	Score = score;
	Score1 = score;
	Time = time;
	flg = true;
};

AbstractScene* Result::Update() {	//�`��ȊO�̍X�V�E�ϐ��̒l�̏������E�O�̉�ʂւ̏㏑��
	if (flg) {
		Score += Time / 60 * 10;
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
	DrawFormatString(20, 110, GetColor(255, 255, 255), "�X�R�A:%d",Score1);
	DrawFormatString(20, 140, GetColor(255, 255, 255), "�c�莞��:%d�b",Time / 60);
	DrawFormatString(20, 170, GetColor(255, 255, 255), "�������_:%d",Score);

	DrawFormatString(20, 200, GetColor(255, 255, 255), "-- �L�[�Ń����L���O�� --");
}

void Result::getResult(int score, int time) {
	score = Score;
	time = Time;
}