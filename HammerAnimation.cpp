#include "HammerAnimation.h"
#include "PadInput.h"

int HammerAnimation::HammerImage;
float HammerAnimation::pox, HammerAnimation::poy;
float HammerAnimation::animx, HammerAnimation::animy, HammerAnimation::angle;
float HammerAnimation::time;
int HammerAnimation::flg;

void HammerAnimation::AnimInit()
{

	animx = 0;
	animy = 0;
	angle = 0;
	flg = 0;
	time = 0;
	HammerImage = LoadGraph("C:/Users/sinzato shuto/Pictures/ÉgÉâÉìÉv.jfif");
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
	DrawRotaGraph(pox + animx, poy + animy, 0.3, angle, HammerImage, TRUE);
}

bool HammerAnimation::SelectAnimation(AnimSelect select, Direction direction)
{
	if (select == AnimSelect::Strong)
	{
		HitAnim(0.4, 40, 0.1, 10, direction);
	}
	if (select == AnimSelect::Normal)
	{
		HitAnim(0.25, 25, 0.1, 10, direction);
	}	
	if (select == AnimSelect::Weak)
	{
		HitAnim(0.1, 10, 0.04, 4, direction);
	}
	if (select == AnimSelect::Miss)
	{
		MissAnimation(direction);
	}

	if (flg == 3)
	{
		animx = 0;
		animy = 0;
		angle = 0;
		flg = 0;
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

//åƒÇ—èoÇµï˚ó·
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