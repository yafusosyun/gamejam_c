#include <math.h>
#include "fps.h"
#include <chrono>
#include <thread>

int fps::mStartTime;
int fps::mCount;
float fps::mFps;

//������
void fps::FpsControll_Initialize() {
    mStartTime = GetNowCount();
    mCount = 0;
    mFps = 0;
}

//FPS����
bool fps::FpsControll_Update() {
    if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
        mStartTime = GetNowCount();
    }
    if (mCount == N) { //40�t���[���ڂȂ畽�ς��v�Z����
        int t = GetNowCount();
        mFps = 1000.f / ((t - mStartTime) / (float)N);
        mCount = 0;
        mStartTime = t;
    }
    mCount++;
    return true;
}

//FPS�\��
void fps::FpsControll_Draw() {
    DrawFormatString(0, 0, GetColor(255, 255, 255), "fps : %.1f", mFps);
}

void fps::FpsControll_Wait() {
    int tookTime = GetNowCount() - mStartTime;  //������������
    int waitTime = mCount * 1000 / FPS - tookTime;  //�҂ׂ�����

    if (waitTime > 0) {
        std::chrono::milliseconds dura(waitTime);
        std::this_thread::sleep_for(dura);  //�ҋ@
    }

}