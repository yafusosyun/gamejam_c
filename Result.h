#pragma once
#include"AbstractScene.h"

class Result : public AbstractScene {
public:
	//�f�X�g���N�^
	virtual ~Result() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;
};


