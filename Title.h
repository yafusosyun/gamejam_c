#pragma once
#include "SceneManager.h"
class Title :
    public SceneManager
{
public:
	Title();

	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;

private:
	int CursorX, CursorY;  //�J�[�\���̍��W
};

