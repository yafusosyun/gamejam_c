#pragma once
#include "DxLib.h"


class HammerAnimation
{
public:
	int HammerImage;

private:
	float pox, poy;  //�n���}�[�̏����ʒu
	float animx, animy, angle; //�n���}�[�𓮂����ϐ�

public:
	int flg;

public:
	HammerAnimation()
	{
		animx = 0;
		animy = 0;
		angle = 0;
		flg = 0;
		HammerImage = LoadGraph("C:/Users/sinzato shuto/Pictures/�g�����v.jfif");
	}
	~HammerAnimation() {};

	void DrawHammer(float x, float y);

	void WeakAnimation();      //�キ�@���Ƃ��̃A�j���[�V����
	void NormalAnimation();    //���ʂɒ@���Ƃ��̃A�j���[�V����
	void StrongAnimation();    //�����@���Ƃ��̃A�j���[�V����
	void MissAnimation();      //�~�X�����Ƃ��̃A�j���[�V����
};

