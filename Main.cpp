#include "DxLib.h"
#include "SceneManager.h"
#include "Timing.h"
#include "PadInput.h"
#include "fps.h"
#include "HammerAnimation.h"
#include "UI.h"
#include "GameMain.h"
#include "nail.h"

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
	LoadImages();

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMain())); 

	//SceneManager sceneMng(/*new Title*/);
	HammerAnimation hammer;


	while (sceneMng.Update() != nullptr && ProcessMessage() != -1)
	{
		ClearDrawScreen();
		PadInput::UpdateKey();
		PadInput::StickControl();
		
		fps::FpsControll_Update();

		fps::FpsControll_Draw();

		hammer.DrawHammer();

		//sceneMng.Draw();

		nail();

		
		//������
		if (PadInput::flgY == 0 && PadInput::inputY < -MARGIN) {
			DrawFormatString(0, 0, 0xffffff, "%d", PadInput::inputY);
		}
		//�����
		if (PadInput::flgY == 0 && PadInput::inputY > MARGIN) {
			DrawFormatString(0, 0, 0xffffff, "%d", PadInput::inputY);
		}
		
		fps::FpsControll_Wait();
		ScreenFlip();
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}