#pragma once
#include "DxLib.h"

class fps
{
private:
	static int mStartTime;      //����J�n����
	static int mCount;          //�J�E���^
	static float mFps;          //fps
	static const int N = 60;  //���ς����T���v����
	static const int FPS = 60;  //�ݒ肵��FPS

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

