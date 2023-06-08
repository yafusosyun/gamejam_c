#pragma once
#include"AbstractScene.h"

class GameMain : public AbstractScene {
private:
	bool flg = true;
	int MainImg;
	static int BGM;

public:
	GameMain();
	//�f�X�X�g���N�^
	virtual ~GameMain() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	static int GetBGM() { return BGM; }
};
