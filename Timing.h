#pragma once
#include "AbstractScene.h"

#define bar 1000

class Timing : public AbstractScene {
private:
	int timing;
	int gauge = 0;
	bool numgaugeflg = true;
	bool gaugeflg = true;
	int tmp = 0;
	const int judgepoint = 50;
	static int judge;
public:
	//�f�X�X�g���N�^
	virtual ~Timing() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	//judge���擾
	static int GetJudge() { return judge; }
};