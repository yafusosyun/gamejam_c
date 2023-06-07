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
	int ScrollY;
	int EndTime;  //�I��鎞��
	const int FontSiz = 50;   //�t�H���g�T�C�Y
};

