#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class Title :
    public AbstractScene
{
private:
	int CursorY;  //�J�[�\���̍��W
	int Font;     //�t�H���g
	int TitileFont; //�^�C�g���p�t�H���g
	const int FontSiz = 65;  //�t�H���g�T�C�Y
	int TitleImage;  //�^�C�g���摜
	int CursorImage; //�J�[�\���摜
	int CursorSE;
	int DecisionSE;

public:
	Title();
	~Title()
	{
		DeleteFontToHandle(Font);
		DeleteGraph(TitleImage);
	}

	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;
};

