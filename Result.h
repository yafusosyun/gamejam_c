#pragma once
#include"AbstractScene.h"

class Result : public AbstractScene {
private:
	int Score, Time, Score1;
	bool flg;

public:
	Result(int score,int time);
	//�f�X�g���N�^
	virtual ~Result() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;

	void getResult(int score, int time);
};


