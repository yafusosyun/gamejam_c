#include "DxLib.h"
#define _USE_MATH_DEFINES
#include "math.h"

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    
    // ウィンドウサイズ設定
    SetGraphMode(1280, 720, 16);
    // ウィンドウモード設定
    ChangeWindowMode(TRUE);

    int Cr,PadInput;
    int x0,x1,i;
    int crs;
	
    if (DxLib_Init() == -1) return -1;

    // 白色の値を取得
    Cr = GetColor(255, 255, 255);

    // 文字列の描画
    //DrawString(150, 240 - 32, "パッドのSTARTボタンを押してください", Cr);
    DrawBox(220, 10, 320, 20, 0xffffff,true);
    
    crs = DrawBox(260, 10, 280, 20, 0xff0000,true);

    for (i = 0; i <= 100; i++)
    {
        DrawFormatString(50, 50, 0xffffff, "%3d", i);

        if (i >= 100)
        {
            for (i = 100; i > 0; i--)
            {
                 DrawFormatString(50, 50, 0xffffff, "%3d", i);
            }
        } 
    }
    
    
    

    // 入力待ち
    PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    while ((PadInput & PAD_INPUT_9) == 0)
    {
        // メッセージ処理
        if (ProcessMessage() == -1)
        {
            break;    // エラーが発生したらループを抜ける
        }

        // パッド１の入力を取得
        PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    }

	DxLib_End();

	return 0;
}
