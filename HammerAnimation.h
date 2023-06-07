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

private:
	static int HammerImage;
	static int StrongSE, NormalSE, WeakSE, MissSE, MissBGM;
	static float pox, poy;  //�n���}�[�̏����ʒu
	static float animx, animy, angle; //�n���}�[�𓮂����ϐ�
	static float time;  //�n���}�[�̓������~�߂�ϐ�
	static int flg;     //�n���}�[�̏グ�����؂�ւ�
	static bool SEflg, BGMflg;  //�n���}�[SE & BGM����񂾂�����

public:
	//HammerAnimation();
	~HammerAnimation() {};

	static void AnimInit();
	static void DrawHammer(float x, float y);

	/* SelectAnimation(�@���Ƃ��̋������̓~�X, �E�ƍ��ǂ��炩) */
	static bool SelectAnimation(AnimSelect select, Direction direction);
	//�@���A�j���[�V����
	static void HitAnim(float _angle, float _y, float _bangle, float _by, AnimSelect select, Direction direction);   
	//�~�X�����Ƃ��̃A�j���[�V����
	static void MissAnimation(Direction direction);
};

