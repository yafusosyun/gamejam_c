#include"DxLib.h"
#include"Result.h"

int page = 0;		//�y�[�W�ړ�

//�G���h�`��
void DrawResult(int key, int& gamemode, int score)
{
	//���U���g��ʂ���I����ʂɈړ�����p
	if (key & PAD_INPUT_4) {
		page = 1;

	}
	switch (page) {
	case 0:
		SetFontSize(46);//�t�H���g�T�C�Y�ݒ�

		//�X�R�A�\��
		DrawFormatString(830, 350, 0xff4040, "%d", score);
		break;
	}
}