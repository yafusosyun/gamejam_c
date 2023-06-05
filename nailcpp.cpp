#include<DxLib.h>
#include<stdio.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*　変数の宣言（クローバル変数）
************************************/
int nailimg;

/***********************************
* 画像読込
************************************/
int LoadImages(void)
{
	//タイトル画像の読込
	nailimg = LoadGraph("images/ringo.png");

	return 0;
}
/*******************
関数宣言
*************************/
/*void nail(void);*///釘のシステム	


/********************
プログラムの開始
***************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hprevInstance, _In_ LPSTR lpCmdLine, _In_
	int nCmdShow)
{
  
	ChangeWindowMode(TRUE); // ウィンドウモード設定
	if (DxLib_Init() == -1) return -1; // DXライブラリ初期化処理

	// test1.bmp の読み込み
	nailimg = LoadGraph("images/ringo.png");

	int b = 0;

	if (b ==0) DrawGraph(0, 0, nailimg, TRUE);



	WaitKey(); // 結果を見るためにキー待ち
	

	DxLib_End(); // DXライブラリ使用の終了処理
	return 0; // ソフトの終了
}

/**********************************
釘のシステム
*****************************/
//void nail(void)
//{
//	int b;
//	scanf_s("%d", &b);
//
//	switch (b) {
//	case 0:
//		DrawGraph(0, 0, nailimg, FALSE);
//
//		break;
//	case 1:
//
//		break;
//	case 2:
//
//		break;
//	case 3:
//
//		break;
//	}
//}