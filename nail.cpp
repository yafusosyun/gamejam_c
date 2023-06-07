#include<DxLib.h>
#include<stdio.h>
#include"nail.h"
#include"Timing.h"

/***********************************
*　変数の宣言（クローバル変数）
************************************/

/*******************
関数宣言
*************************/


/********************
プログラムの開始
***************************/
//int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hprevInstance, _In_ LPSTR lpCmdLine, _In_
//	int nCmdShow)
//{
//  
//	ChangeWindowMode(TRUE); // ウィンドウモード設定
//	if (DxLib_Init() == -1) return -1; // DXライブラリ初期化処理
//
//	//画像読込関数の呼び出し
//	if (LoadImages() == -1) return -1;
//
//	nail();
//
//
//	WaitKey(); // 結果を見るためにキー待ち
//	
//
//	DxLib_End(); // DXライブラリ使用の終了処理
//	return 0; // ソフトの終了
//}

void Nail::Init() {
	count = 0;
	miss = 0;
	fps = 0;
}




/***********************************
* 画像読込
************************************/
int Nail::LoadImages(void)
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
	 FFF = LoadGraph("images/FFT.png");

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
void Nail::nail(void)
{

	switch (count) {

	case 0://釘を打つ前
			DrawGraph(450, 150, Start, TRUE);
			miss = 0;
			break;

	case 1://釘を打つ1回目
		if (judge == 0)
		{
			DrawGraph(450, 150, F, TRUE);//1回目ミス
			miss = 1;
		}
		else
			DrawGraph(450, 150, T, TRUE);//1回目成功
		break;
			
	case 2://釘を打つ2回目
		if (judge == 0)
		{
			if (miss == 1 || miss == 2)
			{
				DrawGraph(450, 150, FF, TRUE);//2回連続失敗
				miss = 2;
			}
			else 
			{
				DrawGraph(450, 150, TF, TRUE);//2回目成功
				miss = 1;
			}
		}
		
		else
		{
			if (miss == 2) {
				DrawGraph(450, 150, FF, TRUE);
			}
			if (miss == 1) {
				DrawGraph(450, 150, TF, TRUE);//2回目成功
			}
			else if (miss == 0) {
				DrawGraph(450, 150, TT, TRUE);//2回目連続成功
			}
		}
		break;

	case 3://釘を打つ3回目
		if (judge == 0)
		{
			if (miss == 0) {
				DrawGraph(450, 150, TTF, TRUE);//2回成功、1回失敗
				miss = 1;
			}

			else if (miss == 1) {
				DrawGraph(450, 150, FFT, TRUE);//2回失敗、1回成功
			}

			else if (miss == 2 || miss == 3)
			{
				DrawGraph(450, 150, FFF, TRUE);//3回連続失敗
				miss = 3;
			}
		}
		else {
			if (miss == 2)
			{
			DrawGraph(450, 150, FFT, TRUE);//2回失敗、1回成功
			}
			else if (miss == 1)
			{
			DrawGraph(450, 150, TTF, TRUE);//2回成功、1回失敗
			}
			else if (miss == 0)
			{
			DrawGraph(450, 150, TTT, TRUE);//3回連続成功
			}
		}
		break;

	case 4://釘を打つ4回目（最後の埋まるところ）
		if (judge == 0)
		{
			if (miss == 3 || miss == 4)
			{
				DrawGraph(450, 150, FFFF, TRUE);//4回連続ミス
				miss = 4;
			}
			
			else if (miss == 3)//3回失敗、1回成功
			{
				DrawGraph(450, 150, FFFT, TRUE);
			}
			else if (miss == 2)
			{
				DrawGraph(450, 150, TTFF, TRUE);//2回失敗、2成功a
			}
			else if (miss == 1)
			{
				DrawGraph(450, 150, TTTF, TRUE);//3回成功、1回失敗a
			}
			else if (miss == 0)
			{
				DrawGraph(450, 150, TTTT, TRUE);//4回連続成功a
			}
		}
		else {
			if (miss == 3)//3回失敗、1回成功
			{
			DrawGraph(450, 150, FFFT, TRUE);
			}
			else if (miss == 2)
			{
			DrawGraph(450, 150, TTFF, TRUE);//2回失敗、2成功a
			}
			else if (miss == 1)
			{
			DrawGraph(450, 150, TTTF, TRUE);//3回成功、1回失敗a
			}
			else if (miss == 0)
			{
			DrawGraph(450, 150, TTTT, TRUE);//4回連続成功a
			}
		}
		break;
			
	}
	DrawFormatString(50, 600, 0xffffff, "miss%d", miss);
	DrawFormatString(50, 650, 0xffffff, "count%d", count);
}

void Nail::Draw() {
	DrawGraph(0, 0, TTTT, TRUE);
}

void Nail::SetNailCount() {
	count += 1;
}

void Nail::Update() {
	judge = Timing::GetJudge();

	if (count == 4 && fps++ >= 60) {
		count = 0;
		fps = 0;
	}
}
