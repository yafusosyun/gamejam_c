#include"DxLib.h"
#include"Result.h"
#include"GameMain.h"
#include"Ranking.h"
#include"PadInput.h"

AbstractScene* Result::Update() {	//�`��ȊO�̍X�V�E�ϐ��̒l�̏������E�O�̉�ʂւ̏㏑��
	if (PadInput::OnClick(XINPUT_BUTTON_A)) {	//�����AA�L�[�������ꂽ��
		return new GameMain();		//�Q�[�����C���Ɉړ�����
	}
	return this;					//����ȊO�Ȃ炱�̃V�[����`�悵������
}

void Result::Draw()const		//�`��Ɋւ��邱�Ƃ���
{
	DrawFormatString(20, 110, GetColor(255, 255, 255), "���ʂ́E�E�E");
}