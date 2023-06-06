#include<DxLib.h>
#include<stdio.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*　変数の宣言（クローバル変数）
************************************/
int isu1;//椅子1画像の変数
int isu2;//椅子2画像の変数
int isu3;//椅子３画像の変数

int miss1;//失敗時1の画像用の変数
int miss2;//失敗時2の画像用の変数
int miss3;//失敗時3の画像用の変数
/*******************
関数宣言
*************************/

int LoadImages(void);//画像読込処理
void nail(void);//釘のシステム	


/********************
プログラムの開始
***************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hprevInstance, _In_ LPSTR lpCmdLine, _In_
	int nCmdShow)
{
  
	ChangeWindowMode(TRUE); // ウィンドウモード設定
	if (DxLib_Init() == -1) return -1; // DXライブラリ初期化処理

	//画像読込関数の呼び出し
	if (LoadImages() == -1) return -1;

	nail();


	WaitKey(); // 結果を見るためにキー待ち
	

	DxLib_End(); // DXライブラリ使用の終了処理
	return 0; // ソフトの終了
}

/***********************************
* 画像読込
************************************/
int LoadImages(void)
{
	//画像の読込
	isu1 = LoadGraph("images/1.png");//椅子１画像の読込
	isu2 = LoadGraph("images/2.png");//椅子２画像の読込
	isu3 = LoadGraph("images/3.png");//椅子３画像の読込

	miss1 =  LoadGraph("images/miss1.png");//ミスしたときの画像の読込
	miss2 = LoadGraph("images/miss1.png");//ミスしたときの画像の読込
	miss3 = LoadGraph("images/miss1.png");//ミスしたときの画像の読込

	//失敗時の椅子画像の読込
	

	return 0;
}

/**********************************
釘のシステム
*****************************/
void nail(void)
{
	int a;
	int count;
	int miss = 0;

	
	switch (count) {

	case 0://釘を打つ前
			DrawGraph(0, 0, isu1, TRUE);
			break;

	case 1://釘を打つ1回目
		if (a == 0)
		{
			DrawGraph(0, 0, miss1, TRUE);//1回目ミス
			miss = 1;
		}
		else
			DrawGraph(0, 0, isu2, TRUE);//1回目成功
			break;
			
		case 2://釘を打つ2回目
			if (a == 0)
			{
				if (miss == 1)
				{
					DrawGraph(0, 0, miss, TRUE);//2回連続失敗
					miss = 2;
				}
			}
				else if(miss == 1)
				{
					DrawGraph(0, 0, miss, TRUE);//2回目成功
					miss = 2;
				}
				else if (miss == 0)
			{
				DrawGraph(0, 0, miss, TRUE);//2回目連続成功
			}
				break;

		case 3://釘を打つ3回目
			if (a == 0)
			{
				if (miss == 2)
				{
					DrawGraph(0, 0, miss, TRUE);//3回連続失敗
				}
			}
			else if (miss == 2)
			{
				DrawGraph(0, 0, miss, TRUE);//2回失敗、1回成功
			}
			else if (miss == 1)
			{
				DrawGraph(0, 0, miss, TRUE);//2回成功、1回失敗
			}
			else if (miss == 0)
			{
				DrawGraph(0, 0, miss, TRUE);//3回連続成功
			}
			break;

		case 4://釘を打つ4回目（最後の埋まるところ）
			if (a == 0)
			{
				if (miss == 3)
				{
					DrawTurnGraph(0, 0, isu2, TRUE);//4回連続ミス
				}
			}
				else if (miss == 3)//3回失敗、1回成功
				{
					DrawGraph(0, 0, miss, TRUE);
				}
				else if (miss == 2)
				{
					DrawGraph(0, 0, miss, TRUE);//2回失敗、2成功
				}
				else if (miss == 1)
			{
				DrawGraph(0, 0, miss, TRUE);//3回成功、1回失敗
			}
				else if (miss == 0)
			{
				DrawGraph(0, 0, miss, TRUE);//4回連続成功
			}
				break;
			
		}

}

