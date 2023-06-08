#include"DxLib.h"
#include"timing.h"
#include"PadInput.h"
#include "UI.h"

int Timing::judge = -1;
bool Timing::gaugeflg = true;
bool Timing::buttonflg = false;
int Timing::comp = 0;

void Timing::Init() {
	judge = -1;
	gauge = 0;
	speed = 1;
	numgaugeflg = true;
	gaugeflg = true;
	buttonflg = false;
	comp = 0;
	judgepoint = 50;
	goodleft = ((bar / 100) * judgepoint - 100);
	goodright = ((bar / 100) * judgepoint + 100);
	greatleft = ((bar / 100) * judgepoint - 10);
	greatright = ((bar / 100) * judgepoint + 10);
}

AbstractScene* Timing::Update() {

	/*PadInput::UpdateKey();*/

	//Aボタンを押すまで0～100を行き来する
	if (PadInput::OnClick(XINPUT_BUTTON_B) == 0) {
		buttonflg = false;
		//0 -> 100
		if (gauge < 100 && numgaugeflg == true && gaugeflg == true) {
			gauge += speed;
			if (gauge >= 99) {
				gauge = 99;
				numgaugeflg = false;
			}
		}
		//100 -> 0
		else if (gauge > 0 && numgaugeflg == false && gaugeflg == true) {
			gauge -= speed;
			if (gauge <= 0) {
				gauge = 0;
				numgaugeflg = true;
			}
		}

		if (gaugeflg == false && fps++ >= 60) {
			fps = 0;
			gaugeflg = true;
			judgepoint = GetRand(100);
			speed = GetRand(5) + 1;
			
			goodleft = ((bar / 100) * judgepoint - (bar / 10));
			if (goodleft < 0) {
				goodleft = 0;
			}

			goodright = ((bar / 100) * judgepoint + (bar / 10));
			if (goodright > bar) {
				goodright = bar;
			}

			greatleft = ((bar / 100) * judgepoint - (bar / 100));
			if (greatleft < 0) {
				greatleft = 0;
			}

			greatright = ((bar / 100) * judgepoint + (bar / 100));
			if (greatright > bar) {
				greatright = bar;
			}
		}
	}
	else {
		if (gaugeflg) {
			buttonflg = true;
			tmp = gauge;
			//50を中心とし、誤差1つ以内ならgreat
			if (judgepoint - 1 <= tmp && judgepoint + 1 >= tmp) {
				judge = 2;
				speed += 1;
				comp += 10;
				if (comp > 100) {
					comp = 100;
				}
			}
			//誤差10以内ならgood
			else if (judgepoint - 10 < tmp && judgepoint + 10 > tmp) {
				judge = 1;
				comp += 5;
				if (comp > 100) {
					comp = 100;
				}
			}
			//それ以外ならmiss
			else {
				judge = 0;
				comp -= 3;
				if (comp < 0) {
					comp = 0;
				}
				
			}
			if (comp < 0)comp = 0;//下限を0


			//移動を止める
			if (gaugeflg == true) {
				gaugeflg = false;
			}
		}
	}

	return this;
}

void Timing::Draw() const {
	DrawBox(20, 100, 20 + bar, 150, 0x00ff55, TRUE);
	DrawBox(goodleft + 20, 100, goodright + 20, 150, 0xffff00, TRUE);
	DrawBox(greatleft + 20, 100, greatright + 20, 150, 0xff0000, TRUE);
	DrawBox(20, 100, 20 + bar, 150, 0x000000, FALSE);
	DrawTriangle((gauge * (bar / 100)), 80, (gauge * (bar / 100)) + 40, 80, (gauge * (bar / 100)) + 20, 100, 0xffffff, TRUE);
	DrawBox((gauge * (bar / 100)) + 20 - 2, 100, (gauge * (bar / 100)) + 20 + 2, 150, 0xffffff, TRUE);
	DrawFormatString(990, 430, 0xffffff, "%d %%", comp);
	DrawString(990, 400, "完成度", 0xffffff);
	SetFontSize(100);
	switch (judge)
	{
	case 0:
		DrawString(20, 300, "Miss...", 0x00ff55);
		break;
	case 1:
		DrawString(20, 300, "Good", 0xffff00);
		break;
	case 2:
		DrawString(20, 300, "Great!!", 0xff0000);
		break;
	default:
		break;
	}
}