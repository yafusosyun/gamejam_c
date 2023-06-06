#include "HammerAnimation.h"
#include "PadInput.h"

void HammerAnimation::DrawHammer(float x, float y)
{
	pox = x;
	poy = y;
	DrawRotaGraph(pox + animx, poy + animy, 0.3, angle, HammerImage, TRUE);
}

void HammerAnimation::WeakAnimation()
{
	
	switch(flg)
	{
	case 0:
		if (angle > -1.6) {
			angle -= 0.1;
			animy += 10;
			break;
		}
		else
		{
			flg = 1;
			break;
		}

	case 1:
		if (angle <= 0) {
			angle += 0.04;
			animy -= 4;
			break;
		}
		else
		{
			flg = 2;
			break;
		}

	default:
		break;
	}
}

void HammerAnimation::NormalAnimation()
{
	switch (flg)
	{
	case 0:
		if (angle > -1.6) {
			angle -= 0.25;
			animy += 25;
			break;
		}
		else
		{
			flg = 1;
			break;
		}

	case 1:
		if (angle <= 0) {
			angle += 0.1;
			animy -= 10;
			break;
		}
		else
		{
			flg = 2;
			break;
		}

	default:
		break;
	}
}

void HammerAnimation::StrongAnimation()
{
	switch (flg)
	{
	case 0:
		if (angle > -1.6) {
			angle -= 0.4;
			animy += 40;
			break;
		}
		else
		{
			flg = 1;
			break;
		}

	case 1:
		if (angle <= 0) {
			angle += 0.1;
			animy -= 10;
			break;
		}
		else
		{
			flg = 2;
			break;
		}

	default:
		break;
	}
}

void HammerAnimation::MissAnimation()
{
	if (angle > -2.5) {
		angle -= 0.4;
		animy += 40;
	}
}