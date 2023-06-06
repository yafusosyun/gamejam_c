#pragma once
#include "AbstractScene.h"
class SceneManager : public AbstractScene
{
private:
	AbstractScene* mScene;   //���݂̃V�[��

public:
	//�R���X�g���N�^
	SceneManager(AbstractScene* scene) :mScene(scene) {};

	//�f�X�g���N�^
	~SceneManager() {
		delete mScene;
	}

	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;
};