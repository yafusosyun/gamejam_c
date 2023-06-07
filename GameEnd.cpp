#include "GameEnd.h"
#include "DxLib.h"

#define WINDOW_CENTER 1280*0.35
#define HEIGHT_CENTER 720*0.5

GameEnd::GameEnd()
{
	ScrollY = 0;
	EndTime = HEIGHT_CENTER;
	Font = CreateFontToHandle("UD デジタル 教科書体 NP-B", FontSiz, 7, DX_FONTTYPE_ANTIALIASING_EDGE, -1, 3);
	EndImage = LoadGraph("images/End.png");
}

AbstractScene* GameEnd::Update()
{
	if ((1000 + FontSiz) - ScrollY < EndTime)
	{
		return nullptr;
	}
	else
	{
		++ScrollY;
	}

	return this;
}

void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImage, FALSE);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 730-ScrollY, "制作", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)-50, (760+FontSiz)-ScrollY, "Cグループ", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 50, (860+FontSiz)-ScrollY, "利用素材サイト", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 100, (910+FontSiz)-ScrollY, "画像", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 100, (960+FontSiz)-ScrollY, "BGM・SE", 0x4169E1, Font, 0xffffff);
	DrawStringToHandle(static_cast<int>(WINDOW_CENTER)- 100, (1100+FontSiz)-ScrollY, "Thank you for playing!", 0x4169E1, Font, 0xffffff);
}
