#include "UI.h"
#include "DxLib.h"

void UI::CountDown()  const 
{
	//ƒ^ƒCƒ€‚Ì‰ÁZˆ—
	if (--gWaitTime < 30) {
	}
	SetFontSize(35);
	DrawFormatString(990, 60, 0xffffff, "Time: %d", /*120-*/gWaitTime / 60);
}

void UI::Score()  const 
{
	
	SetFontSize(50);
	DrawFormatString(990, 290, 0xffffff, "%d", gScore);
	DrawString(990, 230, "Score", 0xffffff);

}

void UI::AddScore()
{
	int n;
	if (n >= 50 || n <= 60) {
		n = 3;
	}
	else if (n >= 30 || n < 80 || !(n >= 50 || n <= 60)) {
		n = 2;
	}
	else {
		n = 1;
	}
	gScore += n * 100;
}

int UI::GetTime() 
{
	return gWaitTime;
}