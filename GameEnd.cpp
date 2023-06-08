#include "GameEnd.h"

#define WINDOW_CENTER 1280*0.45
#define WINDOW_HEIGHT 720*0.4

GameEnd::GameEnd()
{
	Time = 0;
	Font = CreateFontToHandle("UD �f�W�^�� ���ȏ��� NP-B", FontSiz, 7, DX_FONTTYPE_ANTIALIASING_EDGE, -1, 3);
	EndImage = LoadGraph("images/End.png");
}

AbstractScene* GameEnd::Update()
{
	//��������Ɉړ�
	for (int i = 0; i < MaxSentence; i++)
	{
		SentenceY[i] -= 1;
	}
	//60�b�o������I���
	if (EndTime < ++Time)
	{
		return nullptr;
	}

	if (SentenceY[MaxSentence-1] <= WINDOW_HEIGHT)
	{
		SentenceY[MaxSentence-1] = static_cast<int>(WINDOW_HEIGHT);
	}

	return this;
}

void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImage, FALSE);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)-5, SentenceY[0], "����", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)-70, SentenceY[1]+FontSiz, "C�O���[�v", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)-100, SentenceY[2] + FontSiz, "���p�f�ރT�C�g", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)-5, SentenceY[3] + FontSiz, "�摜", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 70, SentenceY[4] + FontSiz, "���炷�Ƃ�", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)-80, SentenceY[5] + FontSiz, "BGM�ESE", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 70, SentenceY[6] + FontSiz, "���ʉ����{", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 70, SentenceY[7] + FontSiz, "OtoLogic", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)-240, SentenceY[8] + FontSiz, "Thank you for playing!", 0x4169E1, Font, 0xffffff);

	//�f�o�b�N
	//DrawFormatString(0, 0, 0xffffff, "%d", Time);
}
