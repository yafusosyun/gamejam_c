#pragma once
#include "DxLib.h"

enum class AnimSelect
{
	Strong,
	Normal,
	Weak,
	Miss
};

enum class Direction
{
	Right,
	Left
};

class HammerAnimation
{
public:
	static int HammerImage;

private:
	static float pox, poy;  //ハンマーの初期位置
	static float animx, animy, angle; //ハンマーを動かす変数
	static float time;  //ハンマーの動きを止める変数
	static int flg;     //ハンマーの上げ下げ切り替え
	static int StrongSE, NormalSE, WeakSE, MissSE, MissBGM;
	static bool SEflg, BGMflg;

public:
	//HammerAnimation();
	~HammerAnimation() {};

	static void AnimInit();
	static void DrawHammer(float x, float y);

	/* SelectAnimation(叩くときの強さ又はミス, 右と左どちらか) */
	static bool SelectAnimation(AnimSelect select, Direction direction);
	//叩くアニメーション
	static void HitAnim(float _angle, float _y, float _bangle, float _by, Direction direction);   
	//ミスしたときのアニメーション
	static void MissAnimation(Direction direction);
};

