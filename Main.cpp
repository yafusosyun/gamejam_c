#include "DxLib.h"
#include "SceneManager.h"
#include "Timing.h"
#include "PadInput.h"
#include "UI.h"
#include "InputRankingScene.h"
#include "DrawRankingScene.h"
#include "Ranking.h"

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

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}


	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new InputRankingScene()));

	//SceneManager sceneMng(/*new Title*/);


	while (sceneMng.Update() != nullptr && ProcessMessage() != -1)
	{
		PadInput::UpdateKey();
		ClearDrawScreen();

		sceneMng.Draw();

		ScreenFlip();
		PadInput::UpdateKey();
	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}