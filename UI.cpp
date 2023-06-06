#include "UI.h"
#include "DxLib.h"

void GameSystem::CountDown()  const {
	//ƒ^ƒCƒ€‚Ì‰ÁZˆ—
	if (--gWaitTime < 30) {
	}
	SetFontSize(35);
	DrawFormatString(990, 60, 0xffffff, "Time: %d", /*120-*/gWaitTime / 60);
}

void GameSystem::Score()  const {
	
	SetFontSize(50);
	DrawFormatString(990, 290, 0xfffffff, "%d", gScore);
	DrawString(990, 230, "Score", 0xffffff);

}

int GameSystem::GetTime() {
	return gWaitTime;
}