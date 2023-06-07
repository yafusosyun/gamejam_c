#pragma once
#include "SceneManager.h"
class GameEnd :
    public AbstractScene
{
public:
	GameEnd();

	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;

private:
	int Font;      //�t�H���g
	int EndImage;  //�w�i�摜
	int SentenceY[6] = { 730,760,860,910,960,1100 };
	int Time;
	const int MaxSentence = 6;
	const int EndTime = 1800;  //�I��鎞��
	const int FontSiz = 50;   //�t�H���g�T�C�Y
};

