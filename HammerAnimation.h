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
	static float pox, poy;  //�n���}�[�̏����ʒu
	static float animx, animy, angle; //�n���}�[�𓮂����ϐ�
	static float time;  //�n���}�[�̓������~�߂�ϐ�
	static int flg;     //�n���}�[�̏グ�����؂�ւ�
	static int StrongSE, NormalSE, WeakSE, MissSE, MissBGM;
	static bool SEflg, BGMflg;

public:
	//HammerAnimation();
	~HammerAnimation() {};

	static void AnimInit();
	static void DrawHammer(float x, float y);

	/* SelectAnimation(�@���Ƃ��̋������̓~�X, �E�ƍ��ǂ��炩) */
	static bool SelectAnimation(AnimSelect select, Direction direction);
	//�@���A�j���[�V����
	static void HitAnim(float _angle, float _y, float _bangle, float _by, Direction direction);   
	//�~�X�����Ƃ��̃A�j���[�V����
	static void MissAnimation(Direction direction);
};

