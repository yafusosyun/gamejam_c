#include "SceneManager.h"

AbstractScene* SceneManager::Update()
{
	//���݃V�[���̃A�b�v�f�[�g�����s
	AbstractScene* nextScene = mScene->Update();

	//���̃V�[�������݃V�[���ƈႤ�ꍇ�؂�ւ���
	if (nextScene != mScene)
	{
		delete mScene;
		mScene = nextScene;
	}

	return nextScene;
}

void SceneManager::Draw() const
{
	mScene->Draw();
}