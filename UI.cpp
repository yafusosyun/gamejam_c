#include "UI.h"
#include "DxLib.h"
#include "Timing.h"

void UI::Init() {
	gWaitTime = 3600;
	gScore = 0;
}

void UI::CountDown()  const 
{
	//�^�C���̉��Z����
	/*if (--gWaitTime < 30) {
	}*/
	gWaitTime--;
	
}

int UI::Score()  
{
	Timing::GetJudge();
	//Great�̎�
	if (Timing::GetJudge() == 2) {
		AddScore((Timing::GetJudge() + 1) * 100);
		return 1;
	}
	//Good�̎�
	else if (Timing::GetJudge() == 1) {
		AddScore((Timing::GetJudge() + 1) * 100);
		return 1;
	}
	//Miss�̎�
	else {
		AddScore((Timing::GetJudge() + 1) * 100);
		return 1;
	}

	return 0;
}
void UI::DrawScore() 
{
	//�X�R�A�̕\��
	SetFontSize(50);
	DrawFormatString(990, 290, 0xffffff, "%d", gScore);
	DrawString(990, 230, "Score", 0xffffff);
	
}

int UI::GetTime() 
{
	return gWaitTime;
}

void UI::DrawCountDown() {
	SetFontSize(35);
	DrawFormatString(990, 60, 0xffffff, "Time: %d", /*120-*/gWaitTime / 60);
}
