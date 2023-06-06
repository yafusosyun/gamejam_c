#include<DxLib.h>
#include<stdio.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*　変数の宣言（クローバル変数）
************************************/
int F;//Fは失敗、Tは成功
int FF;
int FFF;
int FFT;
int T;
int TF;
int TT;
int TTF;
int TTT;
int FFFF;
int FFFT;
int TTFF;
int TTTF;
int TTTT;
int Start;//打つ前の画像
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
	//釘を打つ前
	 Start = LoadGraph("images/Start.png");

	 //1回目
	 F = LoadGraph("images/F.png");
	 T = LoadGraph("images/T.png");
	
	
	 //2回目
	 TT = LoadGraph("images/TT.png");
	FF = LoadGraph("images/FF.png");
	TF = LoadGraph("images/TF.png");

	//3回目
	 TTF = LoadGraph("images/TTF.png");
	 TTT = LoadGraph("images/TTT.png");
	 FFT = LoadGraph("images/FFT.png");
	 FFF = LoadGraph("images/FFF.png");

	 //4回目
	 FFFF = LoadGraph("images/FFFF.png");
	 FFFT = LoadGraph("images/FFFT.png");
	 TTFF = LoadGraph("images/TTFF.png");
	 TTTF = LoadGraph("images/TTTF.png");
	 TTTT = LoadGraph("images/TTTT.png");
	return 0;
}

/**********************************
釘のシステム
*****************************/
void nail(void)
{
	int a = 0;
	int count=0;
	int miss = 0;

	
	switch (count) {

	case 0://釘を打つ前
			DrawGraph(0, 0, Start, TRUE);
			break;

	case 1://釘を打つ1回目
		if (a == 0)
		{
			DrawGraph(0, 0, F, TRUE);//1回目ミス
			miss = 1;
		}
		else
			DrawGraph(0, 0, T, TRUE);//1回目成功
			break;
			
		case 2://釘を打つ2回目
			if (a == 0)
			{
				if (miss == 1)
				{
					DrawGraph(0, 0, FF, TRUE);//2回連続失敗
					miss = 2;
				}
			}
				else if(miss == 1)
				{
					DrawGraph(0, 0, TF, TRUE);//2回目成功
					miss = 2;
				}
				else if (miss == 0)
			{
				DrawGraph(0, 0, TT, TRUE);//2回目連続成功
			}
				break;

		case 3://釘を打つ3回目
			if (a == 0)
			{
				if (miss == 2)
				{
					DrawGraph(0, 0, FFF, TRUE);//3回連続失敗
				}
			}
			else if (miss == 2)
			{
				DrawGraph(0, 0, FFT, TRUE);//2回失敗、1回成功
			}
			else if (miss == 1)
			{
				DrawGraph(0, 0, TTF, TRUE);//2回成功、1回失敗
			}
			else if (miss == 0)
			{
				DrawGraph(0, 0, TTT, TRUE);//3回連続成功
			}
			break;

		case 4://釘を打つ4回目（最後の埋まるところ）
			if (a == 0)
			{
				if (miss == 3)
				{
					DrawTurnGraph(0, 0, FFFF, TRUE);//4回連続ミス
				}
			}
				else if (miss == 3)//3回失敗、1回成功
				{
					DrawGraph(0, 0, FFFT, TRUE);
				}
				else if (miss == 2)
				{
					DrawGraph(0, 0, TTFF, TRUE);//2回失敗、2成功a
				}
				else if (miss == 1)
			{
				DrawGraph(0, 0, TTTF, TRUE);//3回成功、1回失敗a
			}
				else if (miss == 0)
			{
				DrawGraph(0, 0, TTTT, TRUE);//4回連続成功a
			}
				break;
			
		}

}

