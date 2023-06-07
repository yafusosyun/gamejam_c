#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class GameEnd :
    public AbstractScene
{
public:
	GameEnd();
	~GameEnd()
	{
		DeleteGraph(EndImage);
		DeleteFontToHandle(Font);
	}

	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;

private:
	int Font;      //�t�H���g
	int EndImage;  //�w�i�摜
	int SentenceY[9] = { 730,760,840,910,980,1100,1170,1240,1500 };
	int Time;
	const int MaxSentence = 9;
	const int EndTime = 1200;  //�I��鎞��  �\��F�P��
	const int FontSiz = 50;   //�t�H���g�T�C�Y
};

