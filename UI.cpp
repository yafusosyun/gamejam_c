#include "UI.h"
#include "DxLib.h"
#include "Timing.h"

void UI::CountDown()  const 
{
	//タイムの加算処理
	if (--gWaitTime < 30) {
	}
	SetFontSize(35);
	DrawFormatString(990, 60, 0xffffff, "Time: %d", /*120-*/gWaitTime / 60);
}

void UI::Score()  
{
	Timing::GetJudge();
	//Greatの時
	if (Timing::GetJudge() == 2) {
		AddScore((Timing::GetJudge() + 1) * 100);
	}
	//Goodの時
	else if (Timing::GetJudge() == 1) {
		AddScore((Timing::GetJudge() + 1) * 100);
	}
	//Missの時
	else {
		AddScore((Timing::GetJudge() + 1) * 100);
	}
}
void UI::DrawScore() 
{
	//スコアの表示
	SetFontSize(50);
	DrawFormatString(990, 290, 0xffffff, "%d", gScore);
	DrawString(990, 230, "Score", 0xffffff);
}

int UI::GetTime() 
{
	return gWaitTime;
}