#pragma once
#include "AbstractScene.h"

#define bar 1000

class Timing : public AbstractScene {
private:
	int timing;
	int gauge = 0;
	int speed = 1;
	bool numgaugeflg = true;
	bool gaugeflg = true;
	int tmp = 0;
	int judgepoint = 50;
	static int judge;

	int goodleft = ((bar / 100) * judgepoint - 100);
	int goodright = ((bar / 100) * judgepoint + 100);
	int greatleft = ((bar / 100) * judgepoint - 10);
	int greatright = ((bar / 100) * judgepoint + 10);

	int fps;
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