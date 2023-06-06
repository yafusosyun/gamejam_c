#pragma once
#include "DxLib.h"


class HammerAnimation
{
public:
	int HammerImage;

private:
	float pox, poy;  //ハンマーの初期位置
	float animx, animy, angle; //ハンマーを動かす変数

public:
	int flg;

public:
	HammerAnimation()
	{
		animx = 0;
		animy = 0;
		angle = 0;
		flg = 0;
		HammerImage = LoadGraph("C:/Users/sinzato shuto/Pictures/トランプ.jfif");
	}
	~HammerAnimation() {};

	void DrawHammer(float x, float y);

	void WeakAnimation();      //弱く叩くときのアニメーション
	void NormalAnimation();    //普通に叩くときのアニメーション
	void StrongAnimation();    //強く叩くときのアニメーション
	void MissAnimation();      //ミスしたときのアニメーション
};

