#include "DxLib.h"
#include "SceneManager.h"
#include "PadInput.h"
#include "fps.h"
#include "HammerAnimation.h"
#include "UI.h"
#include "GameMain.h"
#include "nail.h"
#include "InputRankingScene.h"
#include "DrawRankingScene.h"
#include "Ranking.h"
#include "Title.h"

#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// �E�B���h�E���[�h�ŋN��
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// ��ʃT�C�Y��ύX
	if (SetGraphMode(_SCREEN_WIDHT_, _SCREEN_HEIGHT_, _SCREEN_COLOR_BIT_32_) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	//����������؂�
	//SetWaitVSyncFlag(0);

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}



	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new Title())); 


	//SceneManager sceneMng(/*new Title*/);

	HammerAnimation::AnimInit();

	while (sceneMng.Update() != nullptr && ProcessMessage() != -1 && !PadInput::OnClick(XINPUT_BUTTON_BACK))
	{
		ClearDrawScreen();

		PadInput::UpdateKey();
		PadInput::StickControl();
		
		fps::FpsControll_Update();
		fps::FpsControll_Draw();

		sceneMng.Draw();

		
		//������
		if (PadInput::flgY == 0 && PadInput::inputY < -MARGIN) {
			DrawFormatString(0, 0, 0xffffff, "%d", PadInput::inputY);
		}
		//�����
		if (PadInput::flgY == 0 && PadInput::inputY > MARGIN) {
			DrawFormatString(0, 0, 0xffffff, "%d", PadInput::inputY);
		}

		/*sceneMng.Draw();*/
		//sceneMng.Draw();

		
		fps::FpsControll_Wait();
		ScreenFlip();
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}