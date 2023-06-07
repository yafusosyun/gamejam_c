#include <math.h>
#include "fps.h"
#include <chrono>
#include <thread>

int fps::mStartTime;
int fps::mCount;
float fps::mFps;

//初期化
void fps::FpsControll_Initialize() {
    mStartTime = GetNowCount();
    mCount = 0;
    mFps = 0;
}

//FPS制御
bool fps::FpsControll_Update() {
    if (mCount == 0) { //1フレーム目なら時刻を記憶
        mStartTime = GetNowCount();
    }
    if (mCount == N) { //40フレーム目なら平均を計算する
        int t = GetNowCount();
        mFps = 1000.f / ((t - mStartTime) / (float)N);
        mCount = 0;
        mStartTime = t;
    }
    mCount++;
    return true;
}

//FPS表示
void fps::FpsControll_Draw() {
    DrawFormatString(0, 0, GetColor(255, 255, 255), "fps : %.1f", mFps);
}

void fps::FpsControll_Wait() {
    int tookTime = GetNowCount() - mStartTime;  //かかった時間
    int waitTime = mCount * 1000 / FPS - tookTime;  //待つべき時間

    if (waitTime > 0) {
        std::chrono::milliseconds dura(waitTime);
        std::this_thread::sleep_for(dura);  //待機
    }

}