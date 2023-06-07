#include "DxLib.h"
#include "SceneManager.h"
#include "PadInput.h"
#include "fps.h"
#include "HammerAnimation.h"

#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ウィンドウモードで起動
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// 画面サイズを変更
	if (SetGraphMode(_SCREEN_WIDHT_, _SCREEN_HEIGHT_, _SCREEN_COLOR_BIT_32_) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	//垂直同期を切る
	//SetWaitVSyncFlag(0);

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//SceneManager sceneMng(/*new Title*/);
	HammerAnimation::AnimInit();
	bool f = false;
	bool h = false;

	while (/*sceneMng.Update() != nullptr &&*/ ProcessMessage() != -1 && !PadInput::OnClick(XINPUT_BUTTON_BACK))
	{
		ClearDrawScreen();
		PadInput::UpdateKey();
		PadInput::StickControl();
		
		fps::FpsControll_Update();
		fps::FpsControll_Draw();

		/*sceneMng.Draw();*/



		//下方向
		if (PadInput::flgY == 0 && PadInput::inputY < -MARGIN) {
			DrawString(0, 20, "下", 0xffffff);
		}
		//上方向
		if (PadInput::flgY == 0 && PadInput::inputY > MARGIN) {
			DrawString(0, 20, "上", 0xffffff);
		}
		//左方向
		if (PadInput::flgX == 0 && PadInput::inputX < -MARGIN) {
			DrawString(0, 20, "左", 0xffffff);
		}
		//右方向
		if (PadInput::flgX == 0 && PadInput::inputX > MARGIN) {
			DrawString(0, 20, "右", 0xffffff);
		}
		
		fps::FpsControll_Wait();
		ScreenFlip();
	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}