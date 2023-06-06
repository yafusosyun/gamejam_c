#include"DxLib.h"
#include"Result.h"

int g_ResultImg;					//���U���g�摜�p
int page = 0;		//�y�[�W�ړ�

//�G���h�`��
void DrawResult(int key, int& gamemode, int score)
{
	//���U���g�摜�\��
	DrawGraph(0, 0, g_ResultImg, FALSE);

	static int menuNo = 0;

	//���U���g��ʂ���I����ʂɈړ�����p
	if (key & PAD_INPUT_4) {
		page = 1;

	}
	switch (page) {
	case 0:
		//���U���g�摜�\��
		DrawGraph(0, 0, g_ResultImg, FALSE);
		SetFontSize(46);//�t�H���g�T�C�Y�ݒ�

		//�X�R�A�\��
		DrawFormatString(830, 350, 0xff4040, "%d", score);

		if (key & PAD_INPUT_B)
		{
			switch (menuNo)
			{
			case 0:
				gamemode = 2;	//�Q�[�����C���ɔ��
				break;
			case 1:
				gamemode = 0;	//�^�C�g��
				break;
			case 2:
				gamemode = 7;	//�G���h�ɔ��
				break;
			}

		}
		break;
	}
}
//���U���g�摜�ǂݍ���
int LoadResultImage()
{
	if ((g_ResultImg = LoadGraph("images/Result/Score.png")) == -1)return -1;	//���U���g�摜�Ǎ�

	return 0;
}