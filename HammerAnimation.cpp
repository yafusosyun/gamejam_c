#include "HammerAnimation.h"
#include "PadInput.h"

int HammerAnimation::HammerImage;
float HammerAnimation::pox, HammerAnimation::poy;
float HammerAnimation::animx, HammerAnimation::animy, HammerAnimation::angle;
float HammerAnimation::time;
int HammerAnimation::flg;
int HammerAnimation::StrongSE, HammerAnimation::NormalSE, HammerAnimation::WeakSE;
int HammerAnimation::MissSE, HammerAnimation::MissBGM;
bool HammerAnimation::SEflg, HammerAnimation::BGMflg;

void HammerAnimation::AnimInit()
{

	animx = 0;
	animy = 0;
	angle = 0;
	flg = 0;
	time = 0;
	HammerImage = LoadGraph("images/Hammer.png");
	StrongSE = LoadSoundMem("Hammer_SE/StrongSE.mp3");
	NormalSE = LoadSoundMem("Hammer_SE/NormalSE.mp3");
	WeakSE = LoadSoundMem("Hammer_SE/WeakSE.mp3");
	MissSE = LoadSoundMem("Hammer_SE/MissSE.mp3");
	MissBGM = LoadSoundMem("Hammer_SE/MissBGM.mp3");
	SEflg = true;
	BGMflg = true;
}

void HammerAnimation::DrawHammer(float x, float y)
{
	pox = x;
	poy = y;
	DrawRotaGraph(pox + animx, poy + animy, 0.5, angle, HammerImage, TRUE);
}

bool HammerAnimation::SelectAnimation(int select, Direction direction)
{
	if (select == 2)
	{
		HitAnim(0.4, 40, 0.1, 10, direction);
		if (SEflg) {
			PlaySoundMem(StrongSE, DX_PLAYTYPE_BACK, TRUE);
			SEflg = false;
		}
	}
	if (select == 3)
	{
		HitAnim(0.25, 25, 0.1, 10, direction);
	}	
	if (select == 1)
	{
		HitAnim(0.1, 10, 0.04, 4, direction);
		if (SEflg) {
			PlaySoundMem(NormalSE, DX_PLAYTYPE_BACK, TRUE);
			SEflg = false;
		}
	}
	if (select == 0)
	{
		MissAnimation(direction);
		if (SEflg) {
			PlaySoundMem(MissSE, DX_PLAYTYPE_BACK, TRUE);
			SEflg = false;
		}
	}

	if (flg == 3)
	{
		animx = 0;
		animy = 0;
		angle = 0;
		flg = 0;
		SEflg = true;
		return false;
	}
	else {
		return true;
	}
}

void HammerAnimation::HitAnim(float _angle, float _y, float _bangle, float _by, Direction direction)
{
	if (direction == Direction::Right) {
		switch (flg)
		{
		case 0:
			if (angle < 1.5) {
				angle += _angle;
				animy += _y;
				break;
			}
			else
			{
				flg = 1;
				break;
			}

		case 1:
			if (time++ > 10)
			{
				time = 0;
				flg = 2;
				break;
			}
			break;

		case 2:
			if (angle >= 0) {
				angle -= _bangle;
				animy -= _by;
				break;
			}
			else
			{
				flg = 3;
				break;
			}

		default:
			break;
		}
	}
	else if(direction == Direction::Left)
	{
		switch (flg)
		{
		case 0:
			if (angle > -1.5) {
				angle -= _angle;
				animy += _y;
				break;
			}
			else
			{
				flg = 1;
				break;
			}

		case 1:
			if (time++ > 10)
			{
				time = 0;
				flg = 2;
				break;
			}
			break;

		case 2:
			if (angle <= 0) {
				angle += _bangle;
				animy -= _by;
				break;
			}
			else
			{
				flg = 3;
				break;
			}

		default:
			break;
		}
	}
}

void HammerAnimation::MissAnimation(Direction direction)
{
	if (direction == Direction::Left) {
		if (angle > -2.5 && flg == 0) {
			angle -= 0.4;
			animy += 40;
		}
		else {
			if (time++ > 1 * 60) {
				flg = 3;
				time = 0;
			}
		}
	}
	else if (direction == Direction::Right)
	{
		if (angle < 2.5 && flg == 0) {
			angle += 0.4;
			animy += 40;
		}
		else {
			if (time++ > 1 * 60) {
				flg = 3;
				time = 0;
			}
		}
	}
}

//呼び出し方例
//HammerAnimation::DrawHammer(500, 300);
//if (PadInput::OnClick(XINPUT_BUTTON_A) && !h) {
//	f = true;
//}
//if (PadInput::OnClick(XINPUT_BUTTON_B) && !f) {
//	h = true;
//}
//if (f) {
//	f = HammerAnimation::SelectAnimation(AnimSelect::Miss, Direction::Right);
//}
//if (h) {
//	h = HammerAnimation::SelectAnimation(AnimSelect::Miss, Direction::Left);
//}