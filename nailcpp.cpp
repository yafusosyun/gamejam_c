#include<DxLib.h>
#include<stdlib.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*　変数の宣言（クローバル変数）
************************************/
int nailimag;

/***********************************
* 画像読込
************************************/
int LoadImages(void)
{
	//タイトル画像の読込
	nailimag = LoadGraph("images/nail1");

	return 0;
}
/*******************
関数宣言
*************************/
void nail(void);//釘のシステム	


/********************
プログラムの開始
***************************/
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ウィンドウモードで起動
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	//画像読込関数の呼び出し
	if (LoadImages() == -1);


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

}

/*******************
釘のシステム
*********************/
void nail(void)
{
	int b;

	scanf_s("%d", &b);

	printf("aaaa");
}