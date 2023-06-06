#include"DxLib.h"
#include"timing.h"
#include"PadInput.h"
#include "UI.h"

int Timing::judge = -1;

AbstractScene* Timing::Update() {

	PadInput::UpdateKey();

	//Aボタンを押すまで0～100を行き来する
	if (PadInput::OnClick(XINPUT_BUTTON_A) == 0) {
		//0 -> 100
		if (gauge < 100 && numgaugeflg == true && gaugeflg == true) {
			gauge++;
			if (gauge >= 100) {
				numgaugeflg = false;
			}
		}
		//100 -> 0
		else if (gauge > 0 && numgaugeflg == false && gaugeflg == true) {
			gauge--;
			if (gauge <= 0) {
				numgaugeflg = true;
			}
		}

	}
	else {
		tmp = gauge;
		//50を中心とし、誤差1つ以内ならgreat
		if (judgepoint - 1 <= tmp && judgepoint + 1 >= tmp) {
			judge = 2;
		}
		//誤差10以内ならgood
		else if (judgepoint - 10 < tmp && judgepoint + 10 > tmp) {
			judge = 1;
		}
		//それ以外ならmiss
		else {
			judge = 0;
		}

		//移動を止める
		if (gaugeflg == true) {
			gaugeflg = false;
		}
	}

	return this;
}

void Timing::Draw() const {
	DrawBox(20, 100, 20 + bar, 150, 0xff0000, true);
	DrawBox(400 + 20, 100, 600 + 20, 150, 0x00ff00, true);
	DrawBox(490 + 20, 100, 510 + 20, 150, 0xff00ff, true);
	DrawFormatString((gauge * (bar / 100)) + 20, 100, 0xffffff, "|");
	DrawFormatString(20, 200, 0xffffff, "%d", tmp);
	DrawFormatString(20, 250, 0xffffff, "%d", gaugeflg);
	switch (judge)
	{
	case 0:
		DrawString(20, 300, "miss", 0xffffff);
		break;
	case 1:
		DrawString(20, 300, "good", 0xffffff);
		break;
	case 2:
		DrawString(20, 300, "graet", 0xffffff);
		break;
	default:
		break;
	}
}