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
	int Time;
	const int EndTime = 300;  //�I��鎞��
};

