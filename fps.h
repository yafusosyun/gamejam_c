#pragma once
#include "DxLib.h"

class fps
{
private:
	static int mStartTime;      //測定開始時刻
	static int mCount;          //カウンタ
	static float mFps;          //fps
	static const int N = 60;  //平均を取るサンプル数
	static const int FPS = 60;  //設定したFPS

public:
	fps() {
		mStartTime = GetNowCount();
		mCount = 0;
		mFps = 0;
	}
	void FpsControll_Initialize();
	static bool FpsControll_Update();
	static void FpsControll_Draw();
	static void FpsControll_Wait();
};

