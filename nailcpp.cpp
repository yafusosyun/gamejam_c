#include<DxLib.h>
#include<stdio.h>



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
	nailimag = LoadGraph("images/ringo");

	return 0;
}
/*******************
関数宣言
*************************/
void nail(void);//釘のシステム	


/********************
プログラムの開始
***************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int a;

    if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
    {
        return -1;        // エラーが起きたら直ちに終了
    }

    // test1.bmpの読み込み
     LoadGraph("images/ringo");

    // 読みこんだグラフィックを画面左上に描画
    DrawGraph(100, 100, nailimag, TRUE);



    WaitKey();        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
}