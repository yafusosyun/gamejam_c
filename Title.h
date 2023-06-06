#pragma once
#include "SceneManager.h"
#include "DxLib.h"
class Title :
    public AbstractScene
{
private:
	int CursorY;  //�J�[�\���̍��W
	int Font;     //�t�H���g
	int FontSiz;  //�t�H���g�T�C�Y

public:
	Title();
	~Title()
	{
		DeleteFontToHandle(Font);
	}

	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;
};

