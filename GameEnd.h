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
	int SentenceY[9] = { 730,760,880,950,1020,1100,1170,1240,1400 };
	int Time;
	const int MaxSentence = 9;
	const int EndTime = 1300;  //�I��鎞��
	const int FontSiz = 50;   //�t�H���g�T�C�Y
};

